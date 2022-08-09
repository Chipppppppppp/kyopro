#pragma once
#include <cstddef>
#include <iterator>
#include <queue>
#include <limits>
#include <stack>
#include <type_traits>
#include <utility>

#if defined(__STRICT_ANSI__) && defined(__SIZEOF_INT128__)
template<>
struct std::is_integral<__int128_t>: std::true_type {};
template<>
struct std::is_integral<__uint128_t>: std::true_type {};
#endif


namespace kyopro {
    template<std::size_t size>
    struct int_least {
    private:
        static constexpr auto get_type() noexcept {
            static_assert(size <= 128, "Integer size is too large");
            if constexpr (size <= 8) return std::int_least8_t{};
            else if constexpr (size <= 16) return std::int_least16_t{};
            else if constexpr (size <= 32) return std::int_least32_t{};
            else if constexpr (size <= 64) return std::int_least64_t{};
            else return __int128_t{};
        }

    public:
        using type = decltype(get_type());
    };

    template<std::size_t size>
    using int_least_t = typename int_least<size>::type;

    template<std::size_t size>
    struct uint_least {
    private:
        static constexpr auto get_type() noexcept {
            static_assert(size <= 128, "Integer size is too large");
            if constexpr (size <= 8) return std::uint_least8_t{};
            else if constexpr (size <= 16) return std::uint_least16_t{};
            else if constexpr (size <= 32) return std::uint_least32_t{};
            else if constexpr (size <= 64) return std::uint_least64_t{};
            else return __uint128_t{};
        }

    public:
        using type = decltype(get_type());
    };

    template<std::size_t size>
    using uint_least_t = typename uint_least<size>::type;

    template<class, class = void>
    struct is_iterator: std::false_type {};
    template<class T>
    struct is_iterator<T, std::void_t<typename std::iterator_traits<T>::iterator_category>>: std::true_type {};

    template<class T>
    constexpr bool is_iterator_v = is_iterator<T>::value;

    template<class, class = void>
    struct is_range: std::false_type {};
    template<class T>
    struct is_range<T, std::void_t<decltype(std::begin(std::declval<std::add_lvalue_reference_t<T>>()), std::end(std::declval<std::add_lvalue_reference_t<T>>()))>>: std::true_type {};

    template<class T>
    constexpr bool is_range_v = is_range<T>::value;

    template<class T>
    struct range_iterator {
        using type = std::decay_t<decltype(std::begin(std::declval<T>()))>;
    };

    template<class T>
    using range_iterator_t = typename range_iterator<T>::type;

    template<class T>
    struct range_const_iterator {
        using type = std::decay_t<decltype(std::cbegin(std::declval<T>()))>;
    };

    template<class T>
    using range_const_iterator_t = typename range_iterator<T>::type;

    template<class T>
    struct range_value {
        using type = std::decay_t<decltype(*std::begin(std::declval<T>()))>;
    };

    template<class T>
    using range_value_t = typename range_value<T>::type;

    namespace helper {
        struct CastableToAny {
            template<class T>
            operator T() const noexcept;
        };

        template<class T, std::size_t... idx, std::void_t<decltype(T{((void)idx, CastableToAny{})...})>* = nullptr>
        constexpr bool is_aggregate_initializable(std::index_sequence<idx...>, bool) noexcept {
            return true;
        }
        template<class T, std::size_t... idx>
        constexpr bool is_aggregate_initializable(std::index_sequence<idx...>, char) noexcept {
            return false;
        }

        template<class T, std::size_t n, std::enable_if_t<is_aggregate_initializable<T>(std::make_index_sequence<n>(), false)>* = nullptr>
        constexpr std::size_t aggregate_size_impl() {
            return n;
        }
        template<class T, std::size_t n, std::enable_if_t<!is_aggregate_initializable<T>(std::make_index_sequence<n>(), false)>* = nullptr>
        constexpr std::size_t aggregate_size_impl() {
            static_assert(n != 0, "Aggregate is required");
            return aggregate_size_impl<T, n - 1>();
        }
    } // namespace helper

    template<class T, class = void>
    struct aggregate_size {
        static_assert(std::is_aggregate_v<T>, "Aggregate is required");
        static constexpr std::size_t value = helper::aggregate_size_impl<T, std::numeric_limits<unsigned char>::digits * sizeof(T)>();
    };
    template<class T>
    struct aggregate_size<T, std::void_t<decltype(std::tuple_size<T>::value)>> {
        static_assert(std::is_aggregate_v<T>, "Aggregate is required");
        static constexpr std::size_t value = std::tuple_size_v<T>;
    };
    template<class T>
    constexpr std::size_t aggregate_size_v = aggregate_size<T>::value;

    template<std::size_t idx, class T>
    struct aggregate_element {
        static_assert(std::is_aggregate_v<T>);

    private:
        template<class U>
        struct Type {
            using type = U;
        };

        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 1>* = nullptr>
        static constexpr auto get_type(U aggregate, char) noexcept {
            auto&& [a] = aggregate;
            static_assert(idx < 1, "Tuple index out of range");
            return Type<decltype(a)>{};
        }
        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 2>* = nullptr>
        static constexpr auto get_type(U aggregate, char) noexcept {
            auto&& [a, b] = aggregate;
            static_assert(idx < 2, "Tuple index out of range");
            if constexpr (idx == 0) return Type<decltype(a)>{};
            else return Type<decltype(b)>{};
        }
        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 3>* = nullptr>
        static constexpr auto get_type(U aggregate, char) noexcept {
            auto&& [a, b, c] = aggregate;
            static_assert(idx < 3, "Tuple index out of range");
            if constexpr (idx == 0) return Type<decltype(a)>{};
            else if constexpr (idx == 1) return Type<decltype(b)>{};
            else return Type<decltype(c)>{};
        }
        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 4>* = nullptr>
        static constexpr auto access_impl(U aggregate, char) noexcept {
            auto&& [a, b, c, d] = aggregate;
            static_assert(idx < 4, "Tuple index out of range");
            if constexpr (idx == 0) return Type<decltype(a)>{};
            else if constexpr (idx == 1) return Type<decltype(b)>{};
            else if constexpr (idx == 2) return Type<decltype(c)>{};
            else return Type<decltype(d)>{};
        }
        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 5>* = nullptr>
        static constexpr auto get_type(U aggregate, char) noexcept {
            auto&& [a, b, c, d, e] = aggregate;
            static_assert(idx < 5, "Tuple index out of range");
            if constexpr (idx == 0) return Type<decltype(a)>{};
            else if constexpr (idx == 1) return Type<decltype(b)>{};
            else if constexpr (idx == 2) return Type<decltype(c)>{};
            else if constexpr (idx == 3) return Type<decltype(d)>{};
            else return Type<decltype(e)>{};
        }
        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 6>* = nullptr>
        static constexpr auto get_type(U aggregate, char) noexcept {
            auto&& [a, b, c, d, e, f] = aggregate;
            static_assert(idx < 6, "Tuple index out of range");
            if constexpr (idx == 0) return Type<decltype(a)>{};
            else if constexpr (idx == 1) return Type<decltype(b)>{};
            else if constexpr (idx == 2) return Type<decltype(c)>{};
            else if constexpr (idx == 3) return Type<decltype(d)>{};
            else if constexpr (idx == 4) return Type<decltype(e)>{};
            else return Type<decltype(f)>{};
        }
        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 7>* = nullptr>
        static constexpr auto get_type(U aggregate, char) noexcept {
            auto&& [a, b, c, d, e, f, g] = aggregate;
            static_assert(idx < 7, "Tuple index out of range");
            if constexpr (idx == 0) return Type<decltype(a)>{};
            else if constexpr (idx == 1) return Type<decltype(b)>{};
            else if constexpr (idx == 2) return Type<decltype(c)>{};
            else if constexpr (idx == 3) return Type<decltype(d)>{};
            else if constexpr (idx == 4) return Type<decltype(e)>{};
            else if constexpr (idx == 5) return Type<decltype(f)>{};
            else return Type<decltype(g)>{};
        }
        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 8>* = nullptr>
        static constexpr auto get_type(U aggregate, char) noexcept {
            auto&& [a, b, c, d, e, f, g, h] = aggregate;
            static_assert(idx < 8, "Tuple index out of range");
            if constexpr (idx == 0) return Type<decltype(a)>{};
            else if constexpr (idx == 1) return Type<decltype(b)>{};
            else if constexpr (idx == 2) return Type<decltype(c)>{};
            else if constexpr (idx == 3) return Type<decltype(d)>{};
            else if constexpr (idx == 4) return Type<decltype(e)>{};
            else if constexpr (idx == 5) return Type<decltype(f)>{};
            else if constexpr (idx == 6) return Type<decltype(g)>{};
            else return Type<decltype(h)>{};
        }
        template<class U, std::void_t<std::tuple_element_t<idx, U>>* = nullptr>
        static constexpr auto get_type(U, bool) noexcept {
            return Type<std::tuple_element_t<idx, U>>{};
        }

    public:
        using type = typename decltype(get_type(std::declval<T>(), false))::type;
    };

    template<std::size_t idx, class T>
    using aggregate_element_t = typename aggregate_element<idx, T>::type;

    template<class T>
    struct is_agg: std::conjunction<std::is_aggregate<T>, std::negation<is_range<T>>> {};

    template<class T>
    inline constexpr bool is_agg_v = is_agg<T>::value;
} // namespace kyopro
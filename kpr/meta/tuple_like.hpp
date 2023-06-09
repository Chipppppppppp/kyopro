#pragma once
#include <cstddef>
#include <type_traits>
#include <tuple>
#include <utility>

namespace kpr {
    namespace helper {
        struct CastableToAny {
            template<class T>
            operator T() const noexcept;
        };

        template<class T, std::size_t... idx, std::void_t<decltype(T{((void)idx, CastableToAny{})...})>* = nullptr>
        constexpr bool is_constructible_with(std::index_sequence<idx...>, bool) noexcept {
            return true;
        }
        template<class T, std::size_t... idx>
        constexpr bool is_constructible_with(std::index_sequence<idx...>, char) noexcept {
            return false;
        }

        template<class T, std::size_t n = sizeof(T) * 8, class = void>
        struct constructible_size {
            static_assert(n != 0, "T is not constructible");
            static constexpr std::size_t value = constructible_size<T, n - 1>::value;
        };

        template<class T, std::size_t n>
        struct constructible_size<T, n, std::enable_if_t<is_constructible_with<T>(std::make_index_sequence<n>(), false)>> {
            static constexpr std::size_t value = n;
        };
    } // namespace helper


    // tuple_likeな型Tの大きさを調べる
    template<class T, class = void>
    struct tuple_like_size {
        static constexpr std::size_t value = helper::constructible_size<T>::value;
    };

    template<class T>
    struct tuple_like_size<T, std::void_t<decltype(std::tuple_size<T>::value)>> {
        static constexpr std::size_t value = std::tuple_size_v<T>;
    };

    // tuple_likeな型Tの大きさを調べる
    template<class T>
    inline constexpr std::size_t tuple_like_size_v = tuple_like_size<T>::value;


    // tuple_likeなオブジェクトのidx(0 <= idx < 8)番目を求める関数クラス
    template<class T, class = void>
    struct GetFunction {
        #define GET(...) \
            { \
                auto&& [__VA_ARGS__] = std::forward<U>(tuple_like); \
                return std::get<idx> (std::forward_as_tuple(__VA_ARGS__)); \
            }

        template<std::size_t idx, class U>
        static constexpr decltype(auto) get(U&& tuple_like) noexcept {
            constexpr std::size_t size = tuple_like_size_v<T>;
            static_assert(size != 0, "The size must not be 0");
            static_assert(size < 9, "The size of tuple_like must be less than 9");
            if constexpr (size == 1) GET(a)
            else if constexpr (size == 2) GET(a, b)
            else if constexpr (size == 3) GET(a, b, c)
            else if constexpr (size == 4) GET(a, b, c, d)
            else if constexpr (size == 5) GET(a, b, c, d, e)
            else if constexpr (size == 6) GET(a, b, c, d, e, f)
            else if constexpr (size == 7) GET(a, b, c, d, e, f, g)
            else GET(a, b, c, d, e, f, g, h)
        }

        #undef GET
    };

    template<class T>
    struct GetFunction<T, std::void_t<decltype(std::tuple_size<T>::value)>> {
        template<std::size_t idx, class U>
        static constexpr decltype(auto) get(U&& tuple_like) noexcept {
            return std::get<idx>(std::forward<U>(tuple_like));
        }
    };

    namespace helper {
        template<std::size_t idx>
        struct GetHelper {
            template<class T>
            constexpr decltype(auto) operator ()(T&& tuple_like) const noexcept {
                return GetFunction<std::decay_t<T>>::template get<idx>(std::forward<T>(tuple_like));
            }
        };
    }

    // tuple-likeなオブジェクトのidx(0 <= idx < 8)番目を求める
    template<std::size_t idx>
    inline constexpr helper::GetHelper<idx> get;


    // tuple-likeな型Tのidx(0 <= idx < 8)番目の要素の型を調べる
    template<std::size_t idx, class T>
    struct tuple_like_element {
        using type = std::decay_t<decltype(get<idx>(std::declval<T>()))>;
    };

    // tuple-likeな型Tのidx(0 <= idx < 8)番目の要素の型を調べる
    template<std::size_t idx, class T>
    using tuple_like_element_t = typename tuple_like_element<idx, T>::type;


    // 型Tがtuple_likeか調べる
    template<class T, class = void>
    struct is_tuple_like {
        static constexpr bool value = std::is_aggregate_v<T>;
    };

    template<class T>
    struct is_tuple_like<T, std::void_t<decltype(std::tuple_size<T>::value)>> {
        static constexpr bool value = true;
    };

    // 型Tがtuple_likeか調べる
    template<class T>
    inline constexpr bool is_tuple_like_v = is_tuple_like<T>::value;
} // namespace kpr

#pragma once
#include <cstddef>
#include <iterator>
#include <tuple>
#include <type_traits>
#include <utility>

namespace kpr {
    namespace helper {
        template<class T>
        struct is_integer_helper {
            static constexpr bool value = std::is_integral_v<T>;
        };

        #ifdef __SIZEOF_INT128__
        template<>
        struct is_integer_helper<__int128_t> {
            static constexpr bool value = true;
        };
        template<>
        struct is_integer_helper<__uint128_t> {
            static constexpr bool value = true;
        };
        #endif
    } // namespace helper

    // 型Tが整数か調べる
    template<class T>
    struct is_integer {
        static constexpr bool value = helper::is_integer_helper<std::remove_cv_t<T>>::value;
    };
    // 型Tが整数か調べる
    template<class T>
    inline constexpr bool is_integer_v = is_integer<T>::value;

    // 型Tが符号付き整数か調べる
    template<class T>
    struct is_signed_integer {
        static constexpr bool value = is_integer_v<T> && std::is_signed_v<T>;
    };
    // 型Tが符号付き整数か調べる
    template<class T>
    inline constexpr bool is_signed_integer_v = is_signed_integer<T>::value;

    // 型Tが符号無し整数か調べる
    template<class T>
    struct is_unsigned_integer {
        static constexpr bool value = is_integer_v<T> && !std::is_signed_v<T>;
    };
    // 型Tが符号無し整数か調べる
    template<class T>
    inline constexpr bool is_unsigned_integer_v = is_unsigned_integer<T>::value;

    namespace helper {
        template<class T>
        struct is_floating_point_helper {
            static constexpr bool value = std::is_floating_point_v<T>;
        };

        #ifdef __SIZEOF_FLOAT128__
        template<>
        struct is_floating_point_helper<__float128> {
            static constexpr bool value = true;
        };
        #endif
    } // namespace helper

    // 型Tが浮動小数点数か調べる
    template<class T>
    struct is_floating_point {
        static constexpr bool value = helper::is_floating_point_helper<std::remove_cv_t<T>>::value;
    };
    // 型Tが浮動小数点数か調べる
    template<class T>
    inline constexpr bool is_floating_point_v = is_floating_point<T>::value;

    // 型Tが算術型か調べる
    template<class T>
    struct is_arithmetic {
        static constexpr bool value = is_integer_v<T> || is_floating_point_v<T>;
    };
    // 型Tが算術型か調べる
    template<class T>
    inline constexpr bool is_arithmetic_v = is_arithmetic<T>::value;

    // 型Tがスカラーか調べる
    template<class T>
    struct is_scalar {
        static constexpr bool value = is_arithmetic_v<T> || std::is_enum_v<T> || std::is_pointer_v<T> || std::is_member_pointer_v<T> || std::is_null_pointer_v<T>;
    };
    // 型Tがスカラーか調べる
    template<class T>
    inline constexpr bool is_scalar_v = is_scalar<T>::value;

    // size以上の大きさを持つ最小の符号付き整数を調べる
    template<std::size_t size>
    struct int_least {
    private:
        static constexpr auto get_type() noexcept {
            static_assert(size <= 128, "The given integer type is too large");
            if constexpr (size <= 8) return std::int_least8_t{};
            else if constexpr (size <= 16) return std::int_least16_t{};
            else if constexpr (size <= 32) return std::int_least32_t{};
            else if constexpr (size <= 64) return std::int_least64_t{};
            else return __int128_t{};
        }

    public:
        using type = decltype(get_type());
    };
    // size以上の大きさを持つ最小の符号付き整数を調べる
    template<std::size_t size>
    using int_least_t = typename int_least<size>::type;

    // size以上の大きさを持つ最小の符号無し整数を調べる
    template<std::size_t size>
    struct uint_least {
    private:
        static constexpr auto get_type() noexcept {
            static_assert(size <= 128, "The give integer type is too large");
            if constexpr (size <= 8) return std::uint_least8_t{};
            else if constexpr (size <= 16) return std::uint_least16_t{};
            else if constexpr (size <= 32) return std::uint_least32_t{};
            else if constexpr (size <= 64) return std::uint_least64_t{};
            else return __uint128_t{};
        }

    public:
        using type = decltype(get_type());
    };
    // size以上の大きさを持つ最小の符号無し整数を調べる
    template<std::size_t size>
    using uint_least_t = typename uint_least<size>::type;

    // Tの次に大きい整数型を調べる
    template<class T>
    struct next_integer {
        static_assert(is_integer_v<T>, "The given type must be an integer type");
        static_assert(sizeof(T) <= 8, "The given integer type is too large");
        using type = std::conditional_t<std::is_signed_v<T>, int_least_t<sizeof(T) * 16>, uint_least_t<sizeof(T) * 16>>;
    };
    // Tの次に大きい整数型を調べる
    template<class T>
    using next_integer_t = typename next_integer<T>::type;

    // Tの次に小さい整数型を調べる
    template<class T>
    struct prev_integer {
        static_assert(is_integer_v<T>, "The given type must be an integer type");
        static_assert(sizeof(T) >= 2, "The given integer type is too large");
        using type = std::conditional_t<std::is_signed_v<T>, int_least_t<sizeof(T) * 4>, uint_least_t<sizeof(T) * 4>>;
    };
    // Tの次に小さい整数型を調べる
    template<class T>
    using prev_integer_t = typename prev_integer<T>::type;

    // 型Tがイテレータか調べる
    template<class T, class = void>
    struct is_iterator {
        static constexpr bool value = false;
    };
    template<class T>
    struct is_iterator<T, std::void_t<typename std::iterator_traits<T>::iterator_category>> {
        static constexpr bool value = true;
    };
    // 型Tがイテレータか調べる
    template<class T>
    inline constexpr bool is_iterator_v = is_iterator<T>::value;

    // 型TがRangeか調べる
    template<class T, class = void>
    struct is_range {
        static constexpr bool value = false;
    };
    template<class T>
    struct is_range<T, std::void_t<decltype(std::begin(std::declval<std::add_lvalue_reference_t<T>>()), std::end(std::declval<std::add_lvalue_reference_t<T>>()))>> {
        static constexpr bool value = true;
    };
     // 型TがRangeか調べる
    template<class T>
    inline constexpr bool is_range_v = is_range<T>::value;

    // Range型Tからイテレータの型を調べる
    template<class T>
    struct range_iterator {
        using type = std::decay_t<decltype(std::begin(std::declval<T>()))>;
    };
    // Range型Tからイテレータの型を調べる
    template<class T>
    using range_iterator_t = typename range_iterator<T>::type;

    // Range型Tから読み取り専用イテレータの型を調べる
    template<class T>
    struct range_const_iterator {
        using type = std::decay_t<decltype(std::cbegin(std::declval<T>()))>;
    };
    // Range型Tから読み取り専用イテレータの型を調べる
    template<class T>
    using range_const_iterator_t = typename range_iterator<T>::type;

    // Range型Tから要素の型を調べる
    template<class T>
    struct range_value {
        using type = std::decay_t<decltype(*std::begin(std::declval<T>()))>;
    };
    // Range型Tから要素の型を調べる
    template<class T>
    using range_value_t = typename range_value<T>::type;
} // namespace kpr

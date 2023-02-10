#pragma once
#include <cstddef>
#include <type_traits>
#include <tuple>
#include <utility>
#include "trait.hpp"

namespace kpr {
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

        template<class T, std::size_t n = sizeof(T) * 8, std::enable_if_t<is_aggregate_initializable<T>(std::make_index_sequence<n>(), false)>* = nullptr>
        constexpr std::size_t aggregate_size() {
            return n;
        }
        template<class T, std::size_t n = sizeof(T) * 8, std::enable_if_t<!is_aggregate_initializable<T>(std::make_index_sequence<n>(), false)>* = nullptr>
        constexpr std::size_t aggregate_size() {
            return aggregate_size<T, n - 1>();
        }
    } // namespace helper

    // tuple_likeな型Tの大きさを調べる
    template<class T, class = void>
    struct tuple_like_size {
        static_assert(std::is_aggregate_v<T>, "T must be tuple_like");
        static constexpr std::size_t value = helper::aggregate_size<T>();
    };

    template<class T>
    struct tuple_like_size<T, std::void_t<decltype(std::tuple_size<T>::value)>> {
        static constexpr std::size_t value = std::tuple_size_v<T>;
    };

    // tuple_likeな型Tの大きさを調べる
    template<class T>
    inline constexpr std::size_t tuple_like_size_v = tuple_like_size<T>::value;


    // 型Tがtuple_likeか調べる
    template<class, class = void>
    struct is_tuple_like {
        static constexpr bool value = false;
    };

    template<class T>
    struct is_tuple_like<T, std::enable_if_t<std::is_aggregate_v<T>>> {
        static constexpr bool value = true;
    };

    template<class T>
    struct is_tuple_like<T, std::void_t<decltype(std::tuple_size<T>::value)>> {
        static constexpr bool value = true;
    };

    // 型Tがtuple_likeか調べる
    template<class T>
    inline constexpr bool is_tuple_like_v = is_tuple_like<T>::value;


    // tuple-likeなオブジェクトのidx(0 <= idx < 8)番目を求める関数クラス
    template<class T, class = void>
    struct GetFunction {
        static_assert(is_tuple_like_v<T>, "T is not gettable");
        template<std::size_t idx>
        static constexpr decltype(auto) get(T&& tuple_like) {
            return std::get<idx>(std::forward<T>(tuple_like));
        }
    };

    #define DEFINE_GET(n, ...)                                             \
    template<class T>                                                      \
    struct GetFunction<T, std::enable_if_t<tuple_like_size_v<T> == n>> {   \
        template<std::size_t idx, class U>                                 \
        static constexpr decltype(auto) get(U&& aggregate) noexcept { \
            auto&& [__VA_ARGS__] = std::forward<U>(aggregate);             \
            return std::get<idx>(std::forward_as_tuple(__VA_ARGS__));      \
        }                                                                  \
    };

    DEFINE_GET(1, a)
    DEFINE_GET(2, a, b)
    DEFINE_GET(3, a, b, c)
    DEFINE_GET(4, a, b, c, d)
    DEFINE_GET(5, a, b, c, d, e)
    DEFINE_GET(6, a, b, c, d, e, f)
    DEFINE_GET(7, a, b, c, d, e, f, g)
    DEFINE_GET(8, a, b, c, d, e, f, g, h)

    #undef DEFINE_GET

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
        using type = decltype(get<idx>(std::declval<T>()));
    };

    // tuple-likeな型Tのidx(0 <= idx < 8)番目の要素の型を調べる
    template<std::size_t idx, class T>
    using tuple_like_element_t = typename tuple_like_element<idx, T>::type;
} // namespace kpr

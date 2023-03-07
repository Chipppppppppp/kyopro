#pragma once
#include <type_traits>
#include <utility>
#include "../io/in.hpp"
#include "../io/out.hpp"
#include "../meta/tuple_like.hpp"

namespace kpr {
    template<class Derived, std::size_t _size>
    struct BaseVals {
        using vals_tag = void;
        static constexpr std::size_t size = _size;

    private:
        template<std::size_t i = 0, class T>
        void assign(T&& vals) noexcept {
            if constexpr (i < tuple_like_size_v<Derived>) {
                get<i>(static_cast<Derived&>(*this)) = get<i>(vals);
                assign<i + 1>(std::forward<T>(vals));
            }
        }

    public:
        template<class T, typename std::decay_t<T>::vals_tag* = nullptr>
        BaseVals(T&& vals) noexcept {
            assign(std::forward<T>(vals));
        }

        template<class... Args>
        BaseVals(Args&&... args) noexcept {
            assign(std::forward_as_tuple(std::forward<Args>(args)...));
        }
    };

    template<class T>
    struct tuple_like_size<T, typename T::vals_tag> {
        static constexpr std::size_t value = T::size;
    };

    template<class T>
    struct GetFunction<T, typename T::vals_tag> {
        #define GET(...) \
            { \
                auto&& [__VA_ARGS__] = std::forward<U>(tuple_like); \
                return std::get<idx>(std::forward_as_tuple(__VA_ARGS__)); \
            }
        template<std::size_t idx, class U>
        static constexpr decltype(auto) get(U&& tuple_like) noexcept {
            static_assert(T::size != 0, "The size must not be 0"); 
            if constexpr (T::size == 1) GET(a)
            else if constexpr (T::size == 2) GET(a, b)
            else if constexpr (T::size == 3) GET(a, b, c)
            else if constexpr (T::size == 4) GET(a, b, c, d)
            else if constexpr (T::size == 5) GET(a, b, c, d, e)
        }
    };

    template<class T>
    struct is_tuple_like<T, typename T::vals_tag> {
        static constexpr bool value = true;
    };
}

#define KYOPRO_VALS0() \
    ([] { \
        struct Vals: kpr::BaseVals<Vals, 0> { \
            using kpr::BaseVals<Vals, 0>::BaseVals; \
        }; \
        return Vals{}; \
    })()
#define KYOPRO_VALS1(name0, value0) \
    ([] { \
        struct Vals: kpr::BaseVals<Vals, 1> { \
            using kpr::BaseVals<Vals, 1>::BaseVals; \
            std::decay_t<decltype(value0)> name0; \
        }; \
        return Vals{value0}; \
    })()
#define KYOPRO_VALS2(name0, value0, name1, value1) \
    ([] { \
        struct Vals: kpr::BaseVals<Vals, 2> { \
            using kpr::BaseVals<Vals, 2>::BaseVals; \
            std::decay_t<decltype(value0)> name0; \
            std::decay_t<decltype(value1)> name1; \
        }; \
        return Vals{value0, value1}; \
    })()
#define KYOPRO_VALS3(name0, value0, name1, value1, name2, value2) \
    ([] { \
        struct Vals: kpr::BaseVals<Vals, 3> { \
            using kpr::BaseVals<Vals, 3>::BaseVals; \
            std::decay_t<decltype(value0)> name0; \
            std::decay_t<decltype(value1)> name1; \
            std::decay_t<decltype(value2)> name2; \
        }; \
        return Vals{value0, value1, value2}; \
    })()
#define KYOPRO_VALS4(name0, value0, name1, value1, name2, value2, name3, value3) \
    ([] { \
        struct Vals: kpr::BaseVals<Vals, 4> { \
            using kpr::BaseVals<Vals, 4>::BaseVals; \
            std::decay_t<decltype(value0)> name0; \
            std::decay_t<decltype(value1)> name1; \
            std::decay_t<decltype(value2)> name2; \
            std::decay_t<decltype(value3)> name3; \
        }; \
        return Vals{value0, value1, value2, value3}; \
    })()
#define KYOPRO_VALS5(name0, value0, name1, value1, name2, value2, name3, value3, name4, value4) \
    ([] { \
        struct Vals: kpr::BaseVals<Vals, 5> { \
            using kpr::BaseVals<Vals, 5>::BaseVals; \
            std::decay_t<decltype(value0)> name0; \
            std::decay_t<decltype(value1)> name1; \
            std::decay_t<decltype(value2)> name2; \
            std::decay_t<decltype(value3)> name3; \
            std::decay_t<decltype(value4)> name4; \
        }; \
        return Vals{value0, value1, value2, value3, value4}; \
    })()

#define KYOPRO_OVERLOAD_VALS(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, name, ...) name

#define vals(...) KYOPRO_OVERLOAD_VALS(__VA_ARGS__ __VA_OPT__(,) KYOPRO_VALS5, nullptr, KYOPRO_VALS4, nullptr, KYOPRO_VALS3, nullptr, KYOPRO_VALS2, nullptr, KYOPRO_VALS1, nullptr, KYOPRO_VALS0)(__VA_ARGS__)
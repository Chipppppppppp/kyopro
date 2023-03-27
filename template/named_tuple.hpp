#pragma once
#include <type_traits>
#include <utility>
#include "../io/in.hpp"
#include "../io/out.hpp"
#include "../meta/tuple_like.hpp"

namespace kpr {
    template<class Derived, std::size_t _size>
    struct NamedTupleBase {
        using named_tuple_tag = void;
        static constexpr std::size_t size = _size;

    private:
        template<std::size_t i = 0, class T>
        void assign(T&& named_tuple) noexcept {
            if constexpr (i < tuple_like_size_v<Derived>) {
                get<i>(static_cast<Derived&>(*this)) = get<i>(named_tuple);
                assign<i + 1>(std::forward<T>(named_tuple));
            }
        }

    public:
        template<class T, typename std::decay_t<T>::named_tuple_tag* = nullptr>
        NamedTupleBase(T&& named_tuple) noexcept {
            assign(std::forward<T>(named_tuple));
        }

        template<class... Args>
        NamedTupleBase(Args&&... args) noexcept {
            assign(std::forward_as_tuple(std::forward<Args>(args)...));
        }
    };

    template<class T>
    struct tuple_like_size<T, typename T::named_tuple_tag> {
        static constexpr std::size_t value = T::size;
    };

    template<class T>
    struct GetFunction<T, typename T::named_tuple_tag> {
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
    struct is_tuple_like<T, typename T::named_tuple_tag> {
        static constexpr bool value = true;
    };
}

#define KYOPRO_NAMED_TUPLE0() \
    ([] { \
        struct NamedTuple: kpr::NamedTupleBase<NamedTuple, 0> { \
            using kpr::NamedTupleBase<NamedTuple, 0>::NamedTupleBase; \
        }; \
        return NamedTuple{}; \
    })()
#define KYOPRO_NAMED_TUPLE1(name0, value0) \
    ([] { \
        using Type0 = std::decay_t<decltype(*new value0)>; \
        struct NamedTuple: kpr::NamedTupleBase<NamedTuple, 1> { \
            using kpr::NamedTupleBase<NamedTuple, 1>::NamedTupleBase; \
            Type0 name0; \
        }; \
        alignas(Type0) std::byte storage0[sizeof(Type0)]; \
        Type0* ptr0 = new (storage0) value0; \
        Type0 res0 = std::move(*ptr0); \
        ptr0->~Type0(); \
        return NamedTuple{std::move(res0)}; \
    })()
#define KYOPRO_NAMED_TUPLE2(name0, value0, name1, value1) \
    ([] { \
        using Type0 = std::decay_t<decltype(*new value0)>; \
        using Type1 = std::decay_t<decltype(*new value1)>; \
        struct NamedTuple: kpr::NamedTupleBase<NamedTuple, 2> { \
            using kpr::NamedTupleBase<NamedTuple, 2>::NamedTupleBase; \
            Type0 name0; \
            Type1 name1; \
        }; \
        alignas(Type0) std::byte storage0[sizeof(Type0)]; \
        Type0* ptr0 = new (storage0) value0; \
        Type0 res0 = std::move(*ptr0); \
        ptr0->~Type0(); \
        alignas(Type1) std::byte storage1[sizeof(Type1)]; \
        Type1* ptr1 = new (storage1) value1; \
        Type1 res1 = std::move(*ptr1); \
        ptr1->~Type1(); \
        return NamedTuple{std::move(res0), std::move(res1)}; \
    })()
#define KYOPRO_NAMED_TUPLE3(name0, value0, name1, value1, name2, value2) \
    ([] { \
        using Type0 = std::decay_t<decltype(*new value0)>; \
        using Type1 = std::decay_t<decltype(*new value1)>; \
        using Type2 = std::decay_t<decltype(*new value2)>; \
        struct NamedTuple: kpr::NamedTupleBase<NamedTuple, 3> { \
            using kpr::NamedTupleBase<NamedTuple, 3>::NamedTupleBase; \
            Type0 name0; \
            Type1 name1; \
            Type2 name2; \
        }; \
        alignas(Type0) std::byte storage0[sizeof(Type0)]; \
        Type0* ptr0 = new (storage0) value0; \
        Type0 res0 = std::move(*ptr0); \
        ptr0->~Type0(); \
        alignas(Type1) std::byte storage1[sizeof(Type1)]; \
        Type1* ptr1 = new (storage1) value1; \
        Type1 res1 = std::move(*ptr1); \
        ptr1->~Type1(); \
        alignas(Type2) std::byte storage2[sizeof(Type2)]; \
        Type2* ptr2 = new (storage2) value2; \
        Type2 res2 = std::move(*ptr2); \
        ptr2->~Type2(); \
        return NamedTuple{std:move(res0), std::move(res1), std::move(res2)}; \
    })()
#define KYOPRO_NAMED_TUPLE4(name0, value0, name1, value1, name2, value2, name3, value3) \
    ([] { \
        using Type0 = std::decay_t<decltype(*new value0)>; \
        using Type1 = std::decay_t<decltype(*new value1)>; \
        using Type2 = std::decay_t<decltype(*new value2)>; \
        using Type3 = std::decay_t<decltype(*new value3)>; \
        struct NamedTuple: kpr::NamedTupleBase<NamedTuple, 4> { \
            using kpr::NamedTupleBase<NamedTuple, 4>::NamedTupleBase; \
            Type0 name0; \
            Type1 name1; \
            Type2 name2; \
            Type3 name3; \
        }; \
        alignas(Type0) std::byte storage0[sizeof(Type0)]; \
        Type0* ptr0 = new (storage0) value0; \
        Type0 res0 = std::move(*ptr0); \
        ptr0->~Type0(); \
        alignas(Type1) std::byte storage1[sizeof(Type1)]; \
        Type1* ptr1 = new (storage1) value1; \
        Type1 res1 = std::move(*ptr1); \
        ptr1->~Type1(); \
        alignas(Type2) std::byte storage2[sizeof(Type2)]; \
        Type2* ptr2 = new (storage2) value2; \
        Type2 res2 = std::move(*ptr2); \
        ptr2->~Type2(); \
        alignas(Type3) std::byte storage3[sizeof(Type3)]; \
        Type3* ptr3 = new (storage3) value3; \
        Type3 res3 = std::move(*ptr3); \
        ptr3->~Type3(); \
        return NamedTuple{std:move(res0), std::move(res1), std::move(res2), std::move(res3)}; \
    })()
#define KYOPRO_NAMED_TUPLE5(name0, value0, name1, value1, name2, value2, name3, value3, name4, value4) \
    ([] { \
        using Type0 = std::decay_t<decltype(*new value0)>; \
        using Type1 = std::decay_t<decltype(*new value1)>; \
        using Type2 = std::decay_t<decltype(*new value2)>; \
        using Type3 = std::decay_t<decltype(*new value3)>; \
        using Type4 = std::decay_t<decltype(*new value4)>; \
        struct NamedTuple: kpr::NamedTupleBase<NamedTuple, 5> { \
            using kpr::NamedTupleBase<NamedTuple, 5>::NamedTupleBase; \
            Type0 name0; \
            Type1 name1; \
            Type2 name2; \
            Type3 name3; \
            Type4 name4; \
        }; \
        alignas(Type0) std::byte storage0[sizeof(Type0)]; \
        Type0* ptr0 = new (storage0) value0; \
        Type0 res0 = std::move(*ptr0); \
        ptr0->~Type0(); \
        alignas(Type1) std::byte storage1[sizeof(Type1)]; \
        Type1* ptr1 = new (storage1) value1; \
        Type1 res1 = std::move(*ptr1); \
        ptr1->~Type1(); \
        alignas(Type2) std::byte storage2[sizeof(Type2)]; \
        Type2* ptr2 = new (storage2) value2; \
        Type2 res2 = std::move(*ptr2); \
        ptr2->~Type2(); \
        alignas(Type3) std::byte storage3[sizeof(Type3)]; \
        Type3* ptr3 = new (storage3) value3; \
        Type3 res3 = std::move(*ptr3); \
        ptr3->~Type3(); \
        alignas(Type4) std::byte storage4[sizeof(Type4)]; \
        Type4* ptr4 = new (storage4) value4; \
        Type4 res4 = std::move(*ptr4); \
        ptr4->~Type4(); \
        return NamedTuple{std:move(res0), std::move(res1), std::move(res2), std::move(res3), std::move(res4)}; \
    })()

#define KYOPRO_OVERLOAD_NAMED_TUPLE(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, name, ...) name

#define $$(...) KYOPRO_OVERLOAD_NAMED_TUPLE(__VA_ARGS__ __VA_OPT__(,) KYOPRO_NAMED_TUPLE5, nullptr, KYOPRO_NAMED_TUPLE4, nullptr, KYOPRO_NAMED_TUPLE3, nullptr, KYOPRO_NAMED_TUPLE2, nullptr, KYOPRO_NAMED_TUPLE1, nullptr, KYOPRO_NAMED_TUPLE0)(__VA_ARGS__)

#line 2 "algorithm/bit.hpp"
#include <limits>
#include <type_traits>
#line 2 "meta/settings.hpp"
#include <cstdint>

#ifndef KYOPRO_BASE_INT
#define KYOPRO_BASE_INT std::int64_t
#endif

#ifndef KYOPRO_BASE_UINT
#define KYOPRO_BASE_UINT std::uint64_t
#endif

#ifndef KYOPRO_BASE_FLOAT
#define KYOPRO_BASE_FLOAT double
#endif

#ifndef KYOPRO_DEFAULT_MOD
#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)
#endif

#ifndef KYOPRO_DECIMAL_PRECISION
#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)
#endif

#ifndef KYOPRO_INF_DIV
#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)
#endif

#ifndef KYOPRO_BUFFER_SIZE
#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)
#endif
#line 5 "algorithm/bit.hpp"

namespace kyopro {
  template<class T>
  constexpr KYOPRO_BASE_INT pop_count(T x) noexcept {
    constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;
    static_assert(digits <= std::numeric_limits<unsigned long long>::digits, "Integer size is too large");
    if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_popcount(x);
    else if constexpr (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_popcountl(x);
    else return __builtin_popcountll(x);
  }

  template<class T>
  constexpr KYOPRO_BASE_INT leading_zero(T x) noexcept {
    constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;
    static_assert(digits <= std::numeric_limits<unsigned long long>::digits, "Integer size is too large");
    if (x == 0) return 0;
    if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_clz(x) + digits - std::numeric_limits<unsigned int>::digits;
    else if constexpr (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_clzl(x) + digits - std::numeric_limits<unsigned long>::digits;
    else return __builtin_clzll(x) + digits - std::numeric_limits<unsigned long long>::digits;
  }

  template<class T>
  constexpr KYOPRO_BASE_INT trailing_zero(T x) noexcept {
    constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;
    static_assert(digits <= std::numeric_limits<unsigned long long>::digits, "Integer size is too large");
    if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_ctz(x);
    else if constexpr (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_ctzl(x);
    else return __builtin_ctzll(x);
  }

  template<class T>
  constexpr KYOPRO_BASE_INT bit_len(T x) noexcept {
    constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;
    static_assert(digits <= std::numeric_limits<unsigned long long>::digits, "Integer size is too large");
    if (x == 0) return 0;
    if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return std::numeric_limits<unsigned int>::digits - __builtin_clz(x);
    else if constexpr (digits <= std::numeric_limits<unsigned long>::digits) return std::numeric_limits<unsigned long>::digits - __builtin_clzl(x);
    else return std::numeric_limits<unsigned long long>::digits - __builtin_clzll(x);
  }

  template<class T>
  constexpr KYOPRO_BASE_INT floor_bit(T x) noexcept {
    return bit_len(x >> static_cast<T>(1));
  }

  template<class T>
  constexpr KYOPRO_BASE_INT ceil_bit(T x) noexcept {
    if (x == 0) return 0;
    return bit_len(x - static_cast<T>(1));
  }
}
#line 2 "algorithm/compress.hpp"
#include <algorithm>
#include <functional>
#include <iterator>
#include <unordered_map>
#include <vector>
#line 8 "algorithm/compress.hpp"

namespace kyopro {
  template<class T, class Container = std::unordered_map<typename std::iterator_traits<T>::value_type, KYOPRO_BASE_INT>, class Compare>
  auto compress(T first, T last, Compare comp = std::less<typename std::iterator_traits<T>::value_type>()) {
    std::vector<typename std::iterator_traits<T>::value_type> vec(first, last);
    std::sort(vec.begin(), vec.end(), comp);
    auto end = std::unique(vec.begin(), vec.end());
    Container mem;
    int cnt = -1;
    for (auto i = vec.begin(); i != end; ++i) mem[*i] = ++cnt;
    return mem;
  }
}
#line 2 "algorithm/Hash.hpp"
#include <cstddef>
#line 5 "algorithm/Hash.hpp"
#include <tuple>
#line 7 "algorithm/Hash.hpp"
#include <utility>
#line 3 "meta/trait.hpp"
#include <queue>
#line 5 "meta/trait.hpp"
#include <stack>
#line 9 "meta/trait.hpp"

template<>
struct std::is_integral<__int128_t>: std::true_type {};
template<>
struct std::is_integral<__uint128_t>: std::true_type {};
template<>
struct std::is_floating_point<__float128>: std::true_type {};

namespace kyopro {
  template<KYOPRO_BASE_UINT size>
  struct int_least {
  private:
    static constexpr auto get_type() noexcept {
      static_assert(size <= 128, "Integer size is too large");
      if constexpr (size <= 8) return std::int_least8_t();
      else if constexpr (size <= 16) return std::int_least16_t();
      else if constexpr (size <= 32) return std::int_least32_t();
      else if constexpr (size <= 64) return std::int_least64_t();
      else return __int128_t();
    }

  public:
    using type = decltype(get_type());
  };

  template<KYOPRO_BASE_UINT size>
  using int_least_t = typename int_least<size>::type;

  template<KYOPRO_BASE_UINT size>
  struct uint_least {
  private:
    static constexpr auto get_type() noexcept {
      static_assert(size <= 128, "Integer size is too large");
      if constexpr (size <= 8) return std::uint_least8_t();
      else if constexpr (size <= 16) return std::uint_least16_t();
      else if constexpr (size <= 32) return std::uint_least32_t();
      else if constexpr (size <= 64) return std::uint_least64_t();
      else return __uint128_t();
    }

  public:
    using type = decltype(get_type());
  };

  template<KYOPRO_BASE_UINT size>
  using uint_least_t = typename uint_least<size>::type;

  template<class, class = void>
  struct is_iterator: std::false_type {};
  template<class T>
  struct is_iterator<T, std::void_t<typename std::iterator_traits<T>::iterator_category>>: std::true_type {};

  template<class T>
  constexpr bool is_iterator_v = is_iterator<T>::value;

  template<class, class = void>
  struct is_iterable: std::false_type {};
  template<class T>
  struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<std::add_lvalue_reference_t<T>>()), std::end(std::declval<std::add_lvalue_reference_t<T>>()))>>: std::true_type {};

  template<class T>
  constexpr bool is_iterable_v = is_iterable<T>::value;

  template<class T>
  struct iterable_value {
    using type = std::decay_t<decltype(*std::begin(std::declval<T>()))>;
  };

  template<class T>
  using iterable_value_t = typename iterable_value<T>::type;

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
  }

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
      return Type<decltype(a)>();
    }
    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 2>* = nullptr>
    static constexpr auto get_type(U aggregate, char) noexcept {
      auto&& [a, b] = aggregate;
      static_assert(idx < 2, "Tuple index out of range");
      if constexpr (idx == 0) return Type<decltype(a)>();
      else return Type<decltype(b)>();
    }
    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 3>* = nullptr>
    static constexpr auto get_type(U aggregate, char) noexcept {
      auto&& [a, b, c] = aggregate;
      static_assert(idx < 3, "Tuple index out of range");
      if constexpr (idx == 0) return Type<decltype(a)>();
      else if constexpr (idx == 1) return Type<decltype(b)>();
      else return Type<decltype(c)>();
    }
    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 4>* = nullptr>
    static constexpr auto access_impl(U aggregate, char) noexcept {
      auto&& [a, b, c, d] = aggregate;
      static_assert(idx < 4, "Tuple index out of range");
      if constexpr (idx == 0) return Type<decltype(a)>();
      else if constexpr (idx == 1) return Type<decltype(b)>();
      else if constexpr (idx == 2) return Type<decltype(c)>();
      else return Type<decltype(d)>();
    }
    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 5>* = nullptr>
    static constexpr auto get_type(U aggregate, char) noexcept {
      auto&& [a, b, c, d, e] = aggregate;
      static_assert(idx < 5, "Tuple index out of range");
      if constexpr (idx == 0) return Type<decltype(a)>();
      else if constexpr (idx == 1) return Type<decltype(b)>();
      else if constexpr (idx == 2) return Type<decltype(c)>();
      else if constexpr (idx == 3) return Type<decltype(d)>();
      else return Type<decltype(e)>();
    }
    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 6>* = nullptr>
    static constexpr auto get_type(U aggregate, char) noexcept {
      auto&& [a, b, c, d, e, f] = aggregate;
      static_assert(idx < 6, "Tuple index out of range");
      if constexpr (idx == 0) return Type<decltype(a)>();
      else if constexpr (idx == 1) return Type<decltype(b)>();
      else if constexpr (idx == 2) return Type<decltype(c)>();
      else if constexpr (idx == 3) return Type<decltype(d)>();
      else if constexpr (idx == 4) return Type<decltype(e)>();
      else return Type<decltype(f)>();
    }
    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 7>* = nullptr>
    static constexpr auto get_type(U aggregate, char) noexcept {
      auto&& [a, b, c, d, e, f, g] = aggregate;
      static_assert(idx < 7, "Tuple index out of range");
      if constexpr (idx == 0) return Type<decltype(a)>();
      else if constexpr (idx == 1) return Type<decltype(b)>();
      else if constexpr (idx == 2) return Type<decltype(c)>();
      else if constexpr (idx == 3) return Type<decltype(d)>();
      else if constexpr (idx == 4) return Type<decltype(e)>();
      else if constexpr (idx == 5) return Type<decltype(f)>();
      else return Type<decltype(g)>();
    }
    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 8>* = nullptr>
    static constexpr auto get_type(U aggregate, char) noexcept {
      auto&& [a, b, c, d, e, f, g, h] = aggregate;
      static_assert(idx < 8, "Tuple index out of range");
      if constexpr (idx == 0) return Type<decltype(a)>();
      else if constexpr (idx == 1) return Type<decltype(b)>();
      else if constexpr (idx == 2) return Type<decltype(c)>();
      else if constexpr (idx == 3) return Type<decltype(d)>();
      else if constexpr (idx == 4) return Type<decltype(e)>();
      else if constexpr (idx == 5) return Type<decltype(f)>();
      else if constexpr (idx == 6) return Type<decltype(g)>();
      else return Type<decltype(h)>();
    }
    template<class U, std::void_t<std::tuple_element_t<idx, U>>* = nullptr>
    static constexpr auto get_type(U, bool) noexcept {
      return Type<std::tuple_element_t<idx, U>>();
    }

  public:
    using type = typename decltype(get_type(std::declval<T>(), false))::type;
  };

  template<std::size_t idx, class T>
  using aggregate_element_t = typename aggregate_element<idx, T>::type;

  template<class T>
  struct is_agg: std::conjunction<std::is_aggregate<T>, std::negation<is_iterable<T>>> {};

  template<class T>
  inline constexpr bool is_agg_v = is_agg<T>::value;
}
#line 7 "meta/aggregate.hpp"

namespace kyopro {
  namespace helper {
    #define DEFINE_ACCESS(n, ...) \
    template<std::size_t idx, class T, std::enable_if_t<aggregate_size_v<std::decay_t<T>> == n>* = nullptr>\
    constexpr decltype(auto) access_impl(T&& aggregate, char) noexcept {\
      auto&& [__VA_ARGS__] = std::forward<T>(aggregate);\
      return std::get<idx>(std::forward_as_tuple(__VA_ARGS__));\
    }

    DEFINE_ACCESS(1, a)
    DEFINE_ACCESS(2, a, b)
    DEFINE_ACCESS(3, a, b, c)
    DEFINE_ACCESS(4, a, b, c, d)
    DEFINE_ACCESS(5, a, b, c, d, e)
    DEFINE_ACCESS(6, a, b, c, d, e, f)
    DEFINE_ACCESS(7, a, b, c, d, e, f, g)
    DEFINE_ACCESS(8, a, b, c, d, e, f, g, h)

    template<std::size_t idx, class T, std::void_t<decltype(std::get<idx>(std::declval<std::decay_t<T>>()))>* = nullptr>
    constexpr decltype(auto) access_impl(T&& aggregate, bool) noexcept {
      return std::get<idx>(std::forward<T>(aggregate));
    }

    #undef DEFINE_ACCESS
  }

  template<std::size_t idx, class T>
  constexpr decltype(auto) access(T&& aggregate) noexcept {
    return helper::access_impl<idx>(std::forward<T>(aggregate), false);
  }
}
#line 11 "algorithm/Hash.hpp"

namespace kyopro {
  template<class, class = void>
  struct Hash;

  template<class T>
  struct Hash<T, std::enable_if_t<std::is_scalar_v<T>>>: std::hash<T> {
    using value_type = T;

    constexpr std::size_t operator ()(T a) const noexcept {
      return std::hash<T>::operator ()(a);
    }
  };

  template<class T>
  struct Hash<T, std::enable_if_t<is_agg_v<T>>> {
    using value_type = T;

    template<KYOPRO_BASE_UINT i = 0>
    constexpr std::size_t operator ()(const T& a) const noexcept {
      if constexpr (i == aggregate_size_v<T>) return aggregate_size_v<T>;
      else {
        std::uint_fast64_t seed = operator()<i + 1>(a);
        return seed ^ (Hash<aggregate_element_t<i, T>>()(access<i>(a)) + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4));
      }
    }
  };

  template<class T>
  struct Hash<T, std::enable_if_t<is_iterable_v<T>>>: Hash<iterable_value_t<T>> {
    using value_type = T;

    constexpr std::size_t operator ()(const T& a) const noexcept {
      std::uint_fast64_t seed = a.size();
      for (auto& i: a) seed ^= Hash<iterable_value_t<T>>(i) + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4);
      return seed;
    }
  };
}
#line 2 "meta/constant.hpp"
#include <array>
#line 3 "math/power.hpp"

namespace kyopro {
  template<class T>
  constexpr T power(T a, KYOPRO_BASE_UINT n, T init = 1) noexcept {
    while (n > 0) {
      if (n & 1) init *= a;
      a *= a;
      n >>= 1;
    }
    return init;
  }
}
#line 7 "meta/constant.hpp"

namespace kyopro {
  template<class T>
  inline constexpr T MOD = KYOPRO_DEFAULT_MOD;
  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;

  template<class T>
  inline constexpr T INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;
  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;

  template<class T, KYOPRO_BASE_UINT decimal_precision = KYOPRO_DECIMAL_PRECISION>
  inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<T>(1) / power(10ULL, decimal_precision);
  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;

  template<class T>
  inline constexpr T PI = 3.14159265358979323846;
  inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;
}
#line 4 "function/monoid.hpp"

namespace kyopro {
  template<class T, T _id = 0>
  struct Plus {
    static_assert(std::is_arithmetic_v<T>);
    using value_type = T;
    static constexpr T id = _id;

    constexpr T operator ()(T a, T b) const noexcept { return a + b; }
    constexpr T inverse(T a) const noexcept { return -a; }
  };

  template<class T, T _id = 1>
  struct Mul {
    static_assert(std::is_arithmetic_v<T>);
    using value_type = T;
    static constexpr T id = _id;

    constexpr T operator ()(T a, T b) const noexcept { return a * b; }
    constexpr T inverse(T a) const noexcept {
      static_assert(!std::is_integral_v<T>);
      return 1 / a;
    }
  };

  template<class T, T _id = std::is_integral_v<T> ? -INF<T> : -inf>
  struct Max {
    static_assert(std::is_arithmetic_v<T>);
    using value_type = T;
    static constexpr T id = _id;

    constexpr T operator ()(T a, T b) const noexcept { return a > b ? a : b; }
  };

  template<class T, T _id = std::is_integral_v<T> ? INF<T> : inf>
  struct Min {
    static_assert(std::is_arithmetic_v<T>);
    using value_type = T;
    static constexpr T id = _id;

    constexpr T operator ()(T a, T b) const noexcept { return a < b ? a : b; }
  };
}
#line 4 "function/RecursiveLambda.hpp"

namespace kyopro {
  template<class F>
  struct RecursiveLambda {
    using value_type = F;

  private:
    F func;

  public:
    template<class G>
    constexpr RecursiveLambda(G&& func) noexcept: func(std::forward<G>(func)) {}
    template<class... Args>
    constexpr decltype(auto) operator ()(Args&&... args) const noexcept { return func(*this, std::forward<Args>(args)...); }
  };

  template<class F>
  RecursiveLambda(F&&) -> RecursiveLambda<std::decay_t<F>>;
}
#line 3 "math/div.hpp"

namespace kyopro {
  template<class T, class U>
  constexpr std::common_type_t<T, U> floor_div(T x, U m) noexcept {
    static_assert(std::is_integral_v<T> && std::is_integral_v<U>, "Integer is required");
    if constexpr (std::is_unsigned_v<T> || std::is_unsigned_v<U>) return x / m;
    auto d = x / m;
    return d * m == x ? d : d - ((x < 0) ^ (m < 0));
  }

  template<class T, class U>
  constexpr std::common_type_t<T, U> ceil_div(T x, U m) noexcept { return floor_div(x + m - static_cast<T>(1), m); }
}
#line 5 "math/divisors.hpp"

namespace kyopro {
  template<class Container = std::vector<KYOPRO_BASE_INT>>
  Container divisors(KYOPRO_BASE_UINT n) {
    Container lower, upper;
    std::uint_fast64_t i;
    for (i = 1; i * i < n; ++i) if (n % i == 0) {
      lower.emplace_back(i);
      upper.emplace_back(n / i);
    }
    if (i * i == n) lower.emplace_back(i);
    lower.insert(end(lower), rall(upper));
    return lower;
  }
}
#line 2 "math/DynamicModInt.hpp"
#include <cassert>
#line 6 "math/Montgomery.hpp"

namespace kyopro {
  template<class T>
  struct Montgomery {
    static_assert(std::is_unsigned_v<T>, "Unsigned integer is required");
    using value_type = T;

    T mod;

  private:
    using larger_type = uint_least_t<std::numeric_limits<T>::digits * 2>;

    T r, n2;

  public:
    constexpr void set_mod(T _mod) noexcept {
      mod = _mod;
      n2 = -static_cast<larger_type>(mod) % mod;
      T t = 0;
      r = 0;
      for (int i = 0; i < std::numeric_limits<T>::digits; ++i) {
        if (!(t & 1)) {
          t += mod;
          r += static_cast<T>(1) << static_cast<T>(i);
        }
        t >>= 1;
      }
    }

    constexpr KYOPRO_BASE_INT get_mod() const noexcept {
      return mod;
    }

    Montgomery() noexcept = default;
    Montgomery(T mod) noexcept {
      set_mod(mod);
    }

    constexpr T transform(T x) const noexcept {
      return reduce(static_cast<larger_type>(x) * n2);
    }

    constexpr T inverse_transform(T x) const noexcept {
      T y = reduce(x);
      return y >= mod ? y - mod : y;
    }

    constexpr T reduce(larger_type x) const noexcept {
      return (x + static_cast<larger_type>(static_cast<T>(x) * r) * mod) >> std::numeric_limits<T>::digits;
    }
  };
}
#line 10 "math/DynamicModInt.hpp"

namespace kyopro {
  template<class T, KYOPRO_BASE_UINT _kind = 0>
  struct DynamicModInt {
    static_assert(std::is_unsigned_v<T>, "T must be unsigned integer");
    using value_type = T;
    static constexpr KYOPRO_BASE_INT kind = _kind;

  private:
    using larger_type = uint_least_t<std::numeric_limits<T>::digits * 2>;

    inline static Montgomery<T> montgomery;

  public:
    T value;

    static void set_mod(T mod) noexcept {
      montgomery.set_mod(mod);
    }

    static KYOPRO_BASE_INT get_mod() noexcept {
      return montgomery.mod;
    }

    KYOPRO_BASE_INT get_val() noexcept {
      return montgomery.inverse_transform(value);
    }

    DynamicModInt() noexcept = default;
    DynamicModInt(T value) noexcept: value(montgomery.transform(value % montgomery.mod + montgomery.mod)) {}

    template<class U>
    explicit operator U() const noexcept { return montgomery.inverse_transform(value); }

    static DynamicModInt raw(T value) noexcept {
      DynamicModInt res;
      res.value = montgomery.transform(value);
      return res;
    }

    DynamicModInt power(KYOPRO_BASE_UINT n) const noexcept {
      DynamicModInt res = 1, a = *this;
      while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
      }
      return res;
    }

    DynamicModInt inverse() const noexcept {
      return power(montgomery.mod - 2);
    }

    DynamicModInt operator +() const noexcept { return *this; }

    DynamicModInt operator -() const noexcept { return value == 0 ? 0 : montgomery.mod - value; }

    DynamicModInt& operator ++() noexcept {
      operator +=(DynamicModInt::raw(1));
      return *this;
    }

    DynamicModInt operator ++(int) noexcept {
      DynamicModInt before = *this;
      operator ++();
      return before;
    }

    DynamicModInt& operator --() noexcept {
      operator -=(DynamicModInt::raw(1));
      return *this;
    }

    DynamicModInt operator --(int) noexcept {
      DynamicModInt before = *this;
      operator --();
      return before;
    }

    DynamicModInt& operator +=(DynamicModInt rhs) noexcept {
      if ((value += rhs.value - (montgomery.mod << 1)) > std::numeric_limits<std::make_signed_t<T>>::max()) value += montgomery.mod << 1;
      return *this;
    }

    DynamicModInt& operator -=(DynamicModInt rhs) noexcept {
      if ((value -= rhs.value) > std::numeric_limits<std::make_signed_t<T>>::max()) value += montgomery.mod << 1;
      return *this;
    }

    DynamicModInt& operator *=(DynamicModInt rhs) noexcept {
      value = montgomery.reduce(static_cast<larger_type>(value) * rhs.value);
      return *this;
    }

    DynamicModInt& operator /=(DynamicModInt rhs) noexcept {
      value = montgomery.reduce(static_cast<larger_type>(value) * rhs.inverse().value);
      return *this;
    }

    friend DynamicModInt operator +(DynamicModInt lhs, DynamicModInt rhs) noexcept { return lhs += rhs; }

    friend DynamicModInt operator -(DynamicModInt lhs, DynamicModInt rhs) noexcept { return lhs -= rhs; }

    friend DynamicModInt operator *(DynamicModInt lhs, DynamicModInt rhs) noexcept { return lhs *= rhs; }

    friend DynamicModInt operator /(DynamicModInt lhs, DynamicModInt rhs) noexcept { return lhs /= rhs; }

    friend bool operator ==(DynamicModInt lhs, DynamicModInt rhs) noexcept { return lhs.value == rhs.value; }

    friend bool operator !=(DynamicModInt lhs, DynamicModInt rhs) noexcept { return lhs.value != rhs.value; }

    template<class Scanner>
    void scan(Scanner& scanner) {
      std::int_fast64_t value;
      scanner.scan(value);
      value = montgomery.transform(value % montgomery.mod + montgomery.mod);
    }

    template<class Printer>
    void print(Printer& printer) const {
      printer.print(montgomery.inverse_transform(value));
    }
  };

  template<class T, KYOPRO_BASE_UINT kind>
  struct Hash<DynamicModInt<T, kind>> {
    using value_type = DynamicModInt<T, kind>;

    std::size_t operator ()(DynamicModInt<T, kind> a) const noexcept { return static_cast<std::size_t>(a); }
  };
}
#line 4 "math/euler_phi.hpp"

namespace kyopro {
  constexpr KYOPRO_BASE_UINT euler_phi(KYOPRO_BASE_UINT n) noexcept {
    std::uint_fast64_t res = n;
    if ((n & 1) == 0) {
      res -= res >> 1;
      n >>= 1;
      while ((n & 1) == 0) n >>= 1;
    }
    for (std::uint_fast64_t i = 3; i * i <= n; i += 2) {
      if (n % i == 0) {
        res -= res / i;
        n /= i;
        while (n % i == 0) n /= i;
      }
    }
    if (n != 1) res -= res / n;
    return res;
  }
}
#line 4 "math/factorize.hpp"
#include <numeric>
#include <random>
#line 7 "math/is_prime.hpp"

namespace kyopro {
  template<class T>
  constexpr bool is_prime(T x) {
    using U = std::make_unsigned_t<T>;
    using DynamicModInt = DynamicModInt<U, KYOPRO_BASE_UINT(-1)>;
    U n = x;
    if (n <= 1) return false;
    if (!(n & 1)) return n == 2;
    DynamicModInt::set_mod(n);
    std::uint_fast64_t d = (n - 1) >> trailing_zero(n - 1);
    DynamicModInt one = 1, minus_one = n - 1;
    auto ng = [&](std::uint_fast64_t a) noexcept {
      auto y = DynamicModInt(a).power(d);
      std::uint_fast64_t t = d;
      while (y != one and y != minus_one and t != n - 1) y *= y, t <<= 1;
      if (y != minus_one and !(t & 1)) return true;
      return false;
    };
    if (std::numeric_limits<U>::digits <= 32 || n < (static_cast<U>(1) << 32)) {
      for (auto i: (std::uint_fast64_t[3]){2, 7, 61}) {
        if (n <= i) return true;
        if (ng(i)) return false;
      }
    } else {
      for (auto i: (std::uint_fast64_t[7]){2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (n <= i) return true;
        if (ng(i)) return false;
      }
    }
    return true;
  }
}
#line 11 "math/factorize.hpp"

namespace kyopro {
  template<class T>
  constexpr T pollard_rho(T p, KYOPRO_BASE_UINT c) {
    using U = std::make_unsigned_t<T>;
    using DynamicModInt = DynamicModInt<U, KYOPRO_BASE_UINT(-1)>;
    U n = p;
    DynamicModInt::set_mod(n);
    DynamicModInt cc = c;
    auto f = [=](DynamicModInt x) noexcept { return x * x + cc; };
    auto x = DynamicModInt::raw(1), y = DynamicModInt::raw(2), z = DynamicModInt::raw(1), q = DynamicModInt::raw(1);
    U g = 1;
    const int m = 1 << (floor_bit(n) / 5);
    for (int r = 1; g == 1; r <<= 1) {
      x = y;
      for (int i = 0; i < r; ++i) y = f(y);
      for (int k = 0; k < r && g == 1; k += m) {
        z = y;
        int min = std::min(m, r - k);
        for (int i = 0; i < min; ++i) {
          y = f(y);
          q *= x - y;
        }
        g = std::gcd(static_cast<U>(q), n);
      }
    }
    if (g == n) {
      do {
        z = f(z);
        g = std::gcd(static_cast<U>(x - z), n);
      } while (g == 1);
    }
    return g;
  }

  KYOPRO_BASE_UINT find_factor(KYOPRO_BASE_UINT n) noexcept {
    static std::mt19937_64 mt(std::random_device{}());
    std::uniform_int_distribution<std::uint_fast64_t> rnd(0, n - 1);
    if (is_prime(n)) return n;
    for (int i = 0; i < 100; ++i) {
      std::uint_fast64_t m = pollard_rho(n, rnd(mt));
      if (is_prime(m)) return m;
      n = m;
    }
    return 1;
  }

  template<bool sorted = true, class Container = std::vector<KYOPRO_BASE_INT>>
  Container factorize(KYOPRO_BASE_UINT n) {
    Container res;
    for (int p = 2; p < 100 && p * p <= n; ++p) {
      while (n % p == 0) {
        n /= p;
        res.emplace_back(p);
      }
    }
    while (n > 1) {
      std::uint_fast64_t p = find_factor(n);
      do {
        n /= p;
        res.emplace_back(p);
      } while (n % p == 0);
    }
    if constexpr (sorted) std::sort(res.begin(), res.end());
    return res;
  }
}
#line 4 "math/mod.hpp"

namespace kyopro {
  template<class T, class U>
  constexpr std::common_type_t<T, U> floor_mod(T x, U m) noexcept {
    static_assert(std::is_integral_v<T> && std::is_integral_v<U>, "Integer is required");
    if constexpr (std::is_unsigned_v<T> || std::is_unsigned_v<U>) return x % m;
    return (x %= m) < 0 ? x + m : x;
  }

  template<class T, class U>
  constexpr std::common_type_t<T, U> ceil_mod(T x, U m) noexcept {
    return m - floor_mod(x - 1, m) - static_cast<T>(1);
  }
}
#line 14 "math/ModInt.hpp"

namespace kyopro {
  template<KYOPRO_BASE_UINT m>
  struct ModInt {
    using value_type = uint_least_t<bit_len(m * 2 - 2)>;
    static constexpr KYOPRO_BASE_INT mod = m;

  private:
    static constexpr value_type _mod = m;

  public:
    value_type value;

    static constexpr KYOPRO_BASE_INT get_mod() noexcept {
      return mod;
    }

    constexpr ModInt() noexcept = default;
    template<class T>
    constexpr ModInt(T value) noexcept: value(floor_mod(value, _mod)) {}

    template<class T>
    explicit constexpr operator T() const noexcept { return value; }

    static constexpr ModInt raw(value_type value) noexcept {
      ModInt res;
      res.value = value;
      return res;
    }

    constexpr ModInt power(KYOPRO_BASE_UINT n) const noexcept {
      std::uint_fast64_t res = 1, a = value;
      while (n > 0) {
        if (n & 1) res = res * a % _mod;
        a = a * a % _mod;
        n >>= 1;
      }
      return res;
    }

    constexpr ModInt inverse() const noexcept {
      std::uint_fast64_t a = value, b = _mod;
      std::int_fast64_t u = 1, v = 0;
      while (b > 0) {
        std::uint_fast64_t t = a / b;
        a -= t * b;
        std::swap(a, b);
        u -= t * v;
        std::swap(u, v);
      }
      return floor_mod(u, _mod);
    }

    constexpr ModInt operator +() const noexcept { return *this; }

    constexpr ModInt operator -() const noexcept { return value == 0 ? 0 : _mod - value; }

    constexpr ModInt& operator ++() noexcept {
      if (++value >= _mod) value -= _mod;
      return *this;
    }

    constexpr ModInt operator ++(int) noexcept {
      ModInt before = *this;
      operator ++();
      return before;
    }

    constexpr ModInt& operator --() noexcept {
      if (value == 0) value = _mod;
      --value;
      return *this;
    }

    constexpr ModInt operator --(int) noexcept {
      ModInt before = *this;
      operator --();
      return before;
    }

    constexpr ModInt& operator +=(ModInt rhs) noexcept {
      if ((value += rhs.value) >= _mod) value -= _mod;
      return *this;
    }

    constexpr ModInt& operator -=(ModInt rhs) noexcept {
      if (value < rhs.value) value += _mod;
      value -= rhs.value;
      return *this;
    }

    constexpr ModInt& operator *=(ModInt rhs) noexcept {
      value = static_cast<uint_least_t<bit_len(_mod) * 2>>(value) * rhs.value % _mod;
      return *this;
    }

    constexpr ModInt& operator /=(ModInt rhs) noexcept {
      value = static_cast<uint_least_t<bit_len(_mod) * 2>>(value) * rhs.inverse().value % _mod;
      return *this;
    }

    friend constexpr ModInt operator +(ModInt lhs, ModInt rhs) noexcept { return lhs += rhs; }

    friend constexpr ModInt operator -(ModInt lhs, ModInt rhs) noexcept { return lhs -= rhs; }

    friend constexpr ModInt operator *(ModInt lhs, ModInt rhs) noexcept { return lhs *= rhs; }

    friend constexpr ModInt operator /(ModInt lhs, ModInt rhs) noexcept { return lhs /= rhs; }

    friend constexpr bool operator ==(ModInt lhs, ModInt rhs) noexcept { return lhs.value == rhs.value; }

    friend constexpr bool operator !=(ModInt lhs, ModInt rhs) noexcept { return lhs.value != rhs.value; }

    template<class Scanner>
    void scan(Scanner& scanner) {
      std::int_fast64_t value;
      scanner.scan(value);
      value = floor_mod(value, _mod);
    }

    template<class Printer>
    void print(Printer& printer) const {
      printer.print(value);
    }
  };

  template<KYOPRO_BASE_UINT _mod>
  struct Hash<ModInt<_mod>> {
    using value_type = ModInt<_mod>;
    constexpr std::size_t operator ()(ModInt<_mod> a) const noexcept { return static_cast<std::size_t>(a); }
  };
}
#line 7 "structure/FenwickTree.hpp"

namespace kyopro {
  template<class T, class Op = Plus<T>, class Container = std::vector<T>>
  struct FenwickTree {
    using value_type = T;
    using size_type = KYOPRO_BASE_UINT;
    using reference = T&;
    using const_reference = const T&;
    using operator_type = Op;
    using container_type = Container;

  private:
    [[no_unique_address]] Op op;
    Container tree;

  public:
    FenwickTree() noexcept = default;
    FenwickTree(KYOPRO_BASE_UINT n) noexcept: tree(n, op.id) {}
    template<class C, std::enable_if_t<std::is_same_v<Container, std::decay_t<C>>>>
    FenwickTree(C&& tree): tree(std::forward<C>(tree)) {}

    KYOPRO_BASE_UINT size() noexcept { return tree.size(); }

    void apply(int p, const T& x) {
      ++p;
      while (p <= (int)size()) {
        tree[p - 1] = op(tree[p - 1], x);
        p += p & -p;
      }
    }

    T prod(int r) const {
      T s = op.id;
      while (r > 0) {
        s = op(s, tree[r - 1]);
        r -= r & -r;
      }
      return s;
    }
    T prod(int l, int r) const { return op(prod(r), op.inverse(prod(l))); }

    T all_prod() { return prod(tree.size()); }

    T get(int p) { return op(prod(p + 1), op.inverse(prod(p))); }

    void set(int p, const T& x) { apply(p, op(x, op.inverse(get(p)))); }
  };
}
#line 9 "structure/UnionFind.hpp"

namespace kyopro {
  template<class Container = std::vector<int>>
  struct UnionFind {
    using value_type = iterable_value_t<Container>;
    using container_type = Container;

  private:
    Container par;

  public:
    UnionFind() noexcept = default;
    UnionFind(KYOPRO_BASE_UINT n) noexcept: par(n, -1) {}
    template<class C, std::enable_if_t<std::is_same_v<Container, std::decay_t<C>>>>
    UnionFind(C&& par): par(std::forward<C>(par)) {}

    void resize(KYOPRO_BASE_UINT x) { par.resize(x, -1); }
    void assign(KYOPRO_BASE_UINT x) { par.assign(x, -1); }
    void reset() { std::fill(std::begin(par), std::end(par), -1); }

    KYOPRO_BASE_UINT size() const noexcept { return par.size(); }

    KYOPRO_BASE_INT find(int x) {
      int p = x;
      while (par[p] >= 0) p = par[p];
      while (x != p) {
        int tmp = x;
        x = par[x];
        par[tmp] = p;
      }
      return p;
    }

    bool merge(int x, int y) {
      x = find(x), y = find(y);
      if (x == y) return false;
      if (par[x] > par[y]) {
        int tmp = x;
        x = y;
        y = tmp;
      }
      par[x] += par[y];
      par[y] = x;
      return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    KYOPRO_BASE_INT group_size(int x) { return -par[find(x)]; }

    std::vector<int> group_members(int x) {
      x = find(x);
      std::vector<int> a;
      for (int i = 0; i < (int)(size()); ++i) if (find(i) == x) a.emplace_back(i);
      return a;
    }

    template<class Vector = std::vector<KYOPRO_BASE_INT>>
    Vector roots() const {
      Vector a;
      for (int i = 0; i < (int)(size()); ++i) if (par[i] < 0) a.emplace_back(i);
      return a;
    }

    KYOPRO_BASE_INT group_count() const {
      KYOPRO_BASE_INT cnt = 0;
      for (int i = 0; i < (int)(size()); ++i) if (par[i] < 0) ++cnt;
      return cnt;
    }

    template<class Map = std::unordered_map<KYOPRO_BASE_INT, std::vector<KYOPRO_BASE_INT>>>
    Map all_group_members() {
      Map group_members;
      for (int member = 0; member < (int)(size()); ++member) group_members[find(member)].emplace_back(member);
      return group_members;
    }
  };
}
#line 2 "system/in.hpp"
#include <unistd.h>
#line 6 "system/in.hpp"
#include <cstdio>
#include <string>
#line 14 "system/in.hpp"

namespace kyopro {
  template<KYOPRO_BASE_UINT _buf_size = KYOPRO_BUFFER_SIZE>
  struct Reader {
    static constexpr KYOPRO_BASE_UINT buf_size = _buf_size;

  private:
    int fd, idx;
    std::array<char, buf_size> buffer;

  public:
    Reader() {
      read(fd, buffer.begin(), buf_size);
    }
    Reader(int fd): fd(fd), idx(0), buffer() {
      read(fd, buffer.begin(), buf_size);
    }
    Reader(FILE* fp): fd(fileno(fp)), idx(0), buffer() {
      read(fd, buffer.begin(), buf_size);
    }

    struct iterator {
    private:
      Reader& reader;

    public:
      using difference_type = void;
      using value_type = void;
      using pointer = void;
      using reference = void;
      using iterator_category = std::input_iterator_tag;

      iterator() noexcept = default;
      iterator(Reader& reader) noexcept: reader(reader) {}

      iterator& operator ++() {
        ++reader.idx;
        if (reader.idx == buf_size) {
          read(reader.fd, reader.buffer.begin(), buf_size);
          reader.idx = 0;
        }
        return *this;
      }

      iterator operator ++(int) {
        iterator before = *this;
        operator ++();
        return before;
      }

      char& operator *() const {
        return reader.buffer[reader.idx];
      }
    };

    iterator begin() noexcept {
      return iterator(*this);
    }
  };

  Reader input(0);

  template<class Iterator, KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>
  struct Scanner {
    using iterator_type = Iterator;
    static constexpr KYOPRO_BASE_UINT decimal_precision = _decimal_precision;

  private:
    template<class, class = void>
    struct has_scan: std::false_type {};
    template<class T>
    struct has_scan<T, std::void_t<decltype(std::declval<T>().scan(std::declval<Scanner&>()))>>: std::true_type {};

  public:
    Iterator itr;

    Scanner() noexcept = default;
    Scanner(Iterator itr) noexcept: itr(itr) {}

    void discard_space() {
      while (('\t' <= *itr && *itr <= '\r') || *itr == ' ') ++itr;
    }

    void scan(char& a) {
      discard_space();
      a = *itr;
      ++itr;
    }
    template<class CharT, class Traits>
    void scan(std::basic_string<CharT, Traits>& a) {
      discard_space();
      while ((*itr < '\t' || '\r' < *itr) && *itr != ' ') {
        a += *itr;
        ++itr;
      }
    }
    void scan(bool& a) {
      discard_space();
      while ('0' <= *itr && *itr <= '9') {
        if (*itr != '0') a = true;
        ++itr;
      }
    }
    template<class T, std::enable_if_t<std::is_arithmetic_v<T> && !has_scan<T>::value>* = nullptr>
    void scan(T& a) {
      discard_space();
      bool sgn = false;
      if constexpr (!std::is_unsigned_v<T>) if (*itr == '-') {
        sgn = true;
        ++itr;
      }
      a = 0;
      for (; '0' <= *itr && *itr <= '9'; ++itr) a = a * 10 + *itr - '0';
      if (*itr == '.') {
        ++itr;
        if constexpr (std::is_floating_point_v<T>) {
          constexpr std::uint_fast64_t power_decimal_precision = power(10ULL, decimal_precision);
          T d = 0;
          std::uint_fast64_t i = 1;
          for (; '0' <= *itr && *itr <= '9' && i < power_decimal_precision; i *= 10) {
            d = d * 10 + *itr - '0';
            ++itr;
          }
          a += d / i;
        }
        while ('0' <= *itr && *itr <= '9') ++itr;
      }
      if constexpr (!std::is_unsigned_v<T>) if (sgn) a = -a;
    }
    template<KYOPRO_BASE_UINT i = 0, class T, std::enable_if_t<is_agg_v<T> && !has_scan<T>::value>* = nullptr>
    void scan(T& a) {
      if constexpr (i < std::tuple_size_v<T>) {
        scan(std::get<i>(a));
        scan<i + 1>(a);
      }
    }
    template<class T, std::enable_if_t<is_iterable_v<T> && !has_scan<T>::value>* = nullptr>
    void scan(T& a) {
      for (auto& i: a) scan(i);
    }
    template<class T, std::enable_if_t<has_scan<T>::value>* = nullptr>
    void scan(T& a) {
      a.scan(*this);
    }

    void operator ()() {}
    template<class Head, class... Args>
    void operator ()(Head& head, Args&... args) {
      scan(head);
      operator ()(args...);
    }
  };

  Scanner<Reader<>::iterator> scan(input.begin());
}
#line 14 "system/out.hpp"

namespace kyopro {
  template<KYOPRO_BASE_UINT _buf_size = KYOPRO_BUFFER_SIZE>
  struct Writer {
    static constexpr KYOPRO_BASE_UINT buf_size = _buf_size;

  private:
    int fd, idx;
    std::array<char, buf_size> buffer;

  public:
    Writer() noexcept = default;
    Writer(int fd) noexcept: fd(fd), idx(0), buffer() {}
    Writer(FILE* fp) noexcept: fd(fileno(fp)), idx(0), buffer() {}

    ~Writer() {
      write(fd, buffer.begin(), idx);
    }

    struct iterator {
    private:
      Writer& writer;

    public:
      using difference_type = void;
      using value_type = void;
      using pointer = void;
      using reference = void;
      using iterator_category = std::output_iterator_tag;

      iterator() noexcept = default;
      iterator(Writer& writer) noexcept: writer(writer) {}

      iterator& operator ++() {
        ++writer.idx;
        if (writer.idx == buf_size) {
          write(writer.fd, writer.buffer.begin(), buf_size);
          writer.idx = 0;
        }
        return *this;
      }

      iterator operator ++(int) {
        iterator before = *this;
        operator ++();
        return before;
      }

      char& operator *() const {
        return writer.buffer[writer.idx];
      }

      void flush() const {
        write(writer.fd, writer.buffer.begin(), writer.idx);
      }
    };

    iterator begin() noexcept {
      return iterator(*this);
    }
  };

  Writer output(1), error(2);

  template<class Iterator, bool _sep = true, bool _end = true, bool _debug = false, bool _comment = false, bool _flush = false, KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>
  struct Printer {
    using iterator_type = Iterator;
    static constexpr bool sep = _sep, end = _end, debug = _debug, comment = _comment, flush = _flush;
    static constexpr KYOPRO_BASE_UINT decimal_precision = _decimal_precision;

  private:
    template<class, class = void>
    struct has_print: std::false_type {};
    template<class T>
    struct has_print<T, std::void_t<decltype(std::declval<T>().print(std::declval<Printer&>()))>>: std::true_type {};

  public:

    Iterator itr;

    Printer() noexcept = default;
    Printer(Iterator itr) noexcept: itr(itr) {}

    void print_char(char c) {
      *itr = c;
      ++itr;
    }

    void print_sep() {
      if constexpr (debug) {
        print_char(',');
      }
      print_char(' ');
    }

    void print(char a) {
      if constexpr (debug) print_char('\'');
      print_char(a);
      if constexpr (debug) print_char('\'');
    }
    void print(const char* a) {
      if constexpr (debug) print_char('"');
      for (; *a; ++a) print_char(*a);
      if constexpr (debug) print_char('"');
    }
    template<class CharT, class Traits>
    void print(const std::basic_string<CharT, Traits>& a) {
      if constexpr (debug) print_char('"');
      for (auto i: a) print_char(i);
      if constexpr (debug) print_char('"');
    }
    void print(bool a) {
      print_char(static_cast<char>('0' + a));
    }
    template<class T, std::enable_if_t<std::is_arithmetic_v<T> && !has_print<T>::value>* = nullptr>
    void print(T a) {
      if constexpr (std::is_signed_v<T>) if (a < 0) {
        print_char('-');
        a = -a;
      }
      std::uint_fast64_t p = a;
      a -= p;
      std::string s;
      do {
        s += '0' + p % 10;
        p /= 10;
      } while (p > 0);
      for (auto i = s.rbegin(); i != s.rend(); ++i) print_char(*i);
      if constexpr (std::is_integral_v<T>) return;
      print_char('.');
      for (int i = 0; i < static_cast<int>(decimal_precision); ++i) {
        a *= 10;
        print_char('0' + static_cast<std::uint_fast64_t>(a) % 10);
      }
    }
    template<KYOPRO_BASE_UINT i = 0, class T, std::enable_if_t<is_agg_v<T> && !has_print<T>::value>* = nullptr>
    void print(const T& a) {
      if constexpr (debug && i == 0) print_char('{');
      if constexpr (aggregate_size_v<T> != 0) print(access<i>(a));
      if constexpr (i + 1 < aggregate_size_v<T>) {
        if constexpr (sep) print_sep();
        print<i + 1>(a);
      } else if constexpr (debug) print_char('}');
    }
    template<class T, std::enable_if_t<is_iterable_v<T> && !has_print<T>::value>* = nullptr>
    void print(const T& a) {
      if constexpr (debug) print_char('{');
      if (std::empty(a)) return;
      for (auto i = std::begin(a); ; ) {
        print(*i);
        if (++i != std::end(a)) {
          if constexpr (sep) {
            if constexpr (debug) {
              print_char(',');
              print_char(' ');
            } else if constexpr (std::is_arithmetic_v<std::decay_t<decltype(std::declval<T>()[0])>>) print_char(' ');
            else print_char('\n');
          }
        } else break;
      }
      if constexpr (debug) print_char('}');
    }
    template<class T, std::enable_if_t<has_print<T>::value>* = nullptr>
    void print(const T& a) {
      a.print(*this);
    }

    template<bool first = true>
    void operator ()() {
      if constexpr (comment && first) print_char('#');
      if constexpr (end) print_char('\n');
      if constexpr (flush) itr.flush();
    }
    template<bool first = true, class Head, class... Args>
    void operator ()(Head&& head, Args&&... args) {
      if constexpr (comment && first) {
        print_char('#');
        print_char(' ');
      }
      if constexpr (sep && !first) print_sep();
      print(head);
      operator ()<false>(std::forward<Args>(args)...);
    }
  };

  Printer<Writer<>::iterator, false, false> print(output.begin()), eprint(error.begin());
  Printer<Writer<>::iterator> println(output.begin()), eprintln(error.begin());
}
#line 3 "template/stl.hpp"
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#line 15 "template/stl.hpp"
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#line 25 "template/stl.hpp"
#include <ctgmath>
#include <cwchar>
#include <cwctype>

#line 30 "template/stl.hpp"
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#line 36 "template/stl.hpp"
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#line 43 "template/stl.hpp"
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#line 49 "template/stl.hpp"
#include <ostream>
#line 51 "template/stl.hpp"
#include <set>
#include <sstream>
#line 54 "template/stl.hpp"
#include <stdexcept>
#include <streambuf>
#line 57 "template/stl.hpp"
#include <typeinfo>
#line 59 "template/stl.hpp"
#include <valarray>
#line 61 "template/stl.hpp"

#line 63 "template/stl.hpp"
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#line 71 "template/stl.hpp"
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#line 77 "template/stl.hpp"
#include <typeindex>
#line 80 "template/stl.hpp"
#include <unordered_set>
#line 19 "template/alias.hpp"

namespace kyopro {
  using ll = long long;
  using ull = unsigned long long;
  using lf = double;

  using i8 = std::int8_t;
  using u8 = std::uint8_t;
  using i16 = std::int16_t;
  using u16 = std::uint16_t;
  using i32 = std::int32_t;
  using u32 = std::uint32_t;
  using i64 = std::int64_t;
  using u64 = std::uint64_t;
  using i128 = __int128_t;
  using u128 = __uint128_t;
  using f128 = __float128;

  using mint = ModInt<mod>;
  using dmint = DynamicModInt<KYOPRO_BASE_UINT>;

  template<class T, KYOPRO_BASE_UINT idx, class... Args>
  struct agg_type {
    using type = typename agg_type<T, idx - 1, T, Args...>::type;
  };
  template<class T, class... Args>
  struct agg_type<T, 0, Args...> {
    using type = std::tuple<Args...>;
  };
  template<class T>
  struct agg_type<T, 0, T, T> {
    using type = std::pair<T, T>;
  };

  template<class T, KYOPRO_BASE_UINT idx>
  using agg = typename agg_type<T, idx>::type;
  using ll1 = agg<ll, 1>;
  using ll2 = agg<ll, 2>;
  using ll3 = agg<ll, 3>;
  using ll4 = agg<ll, 4>;
  using ll5 = agg<ll, 5>;

  template<class T>
  using vec = std::vector<T>;
  template<class T>
  using vvec = std::vector<vec<T>>;
  template<class T>
  using vvvec = std::vector<vvec<T>>;
  template<class T>
  using vvvvec = std::vector<vvvec<T>>;
  template<class T>
  using vvvvvec = std::vector<vvvvec<T>>;

  template<class Key, class Compare = std::less<Key>>
  using mset = std::unordered_set<Key, Compare>;
  template<class Key, class T, class Compare = std::less<Key>>
  using mmap = std::unordered_map<Key, T, Compare>;
  template<class Key>
  using hset = std::unordered_set<Key, Hash<Key>>;
  template<class Key, class T>
  using hmap = std::unordered_map<Key, T, Hash<Key>>;
  template<class Key>
  using hmiset = std::unordered_multiset<Key, Hash<Key>>;
  template<class Key, class T>
  using hmmap = std::unordered_multimap<Key, T, Hash<Key>>;
  template<class T, class Compare = std::less<T>, class Container = std::vector<T>>
  using priq = std::priority_queue<T, Container, Compare>;
  template<class T, class Compare = std::greater<T>, class Container = std::vector<T>>
  using heapq = priq<T, Compare, Container>;
}

using namespace std;
using namespace kyopro;
#line 2 "template/amin_amax.hpp"

namespace kyopro {
  template<class T, class U>
  constexpr bool amin(T& a, U&& b) noexcept {
    if (b < a) {
      a = b;
      return true;
    }
    return false;
  }

  template<class T, class U>
  constexpr bool amax(T& a, U&& b) noexcept {
    if (a < b) {
      a = b;
      return true;
    }
    return false;
  }
}
#line 4 "template/constant.hpp"

namespace kyopro {
  inline constexpr std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};
  inline constexpr std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 8> around{{{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}}};
}
#line 4 "template/len.hpp"

namespace kyopro {
  template<class T>
  constexpr KYOPRO_BASE_INT len(T&& a) noexcept {
    return std::size(a);
  }
}
#line 8 "template/macro.hpp"

namespace kyopro::helper {
  template<KYOPRO_BASE_UINT len>
  constexpr KYOPRO_BASE_UINT va_args_size(const char (&s)[len]) noexcept {
    if constexpr (len == 1) return 0;
    KYOPRO_BASE_UINT cnt = 1;
    for (auto i: s) if (i == ',') ++cnt;
    return cnt;
  }

  template<class F, KYOPRO_BASE_UINT... idx>
  auto read_impl(F&& f, std::integer_sequence<KYOPRO_BASE_UINT, idx...>) {
    auto res = std::tuple{(static_cast<void>(idx), f())...};
    scan(res);
    return res;
  }

  Printer<Writer<>::iterator, true, true, true> debug_impl(output.begin());

  template<bool>
  void print_if(const char* s) {
    print(' ', s, ' ', '=', ' ');
  }
  template<>
  void print_if<false>(const char*) {}
}

#define read(init, ...) auto [__VA_ARGS__] = kyopro::helper::read_impl([&] { return init; }, std::make_integer_sequence<KYOPRO_BASE_UINT, kyopro::helper::va_args_size(#__VA_ARGS__)>())
#define debug(...) (kyopro::print('#', 'l', 'i', 'n', 'e', ' ', __LINE__, ':'), kyopro::helper::print_if<kyopro::helper::va_args_size(#__VA_ARGS__) != 0>(#__VA_ARGS__), kyopro::helper::debug_impl(__VA_ARGS__))

#define KYOPRO_OVERLOAD_MACRO(_1, _2, _3, _4, name, ...) name

#define KYOPRO_REP0() for (; ; )
#define KYOPRO_REP1(last) KYOPRO_REP2(KYOPRO_COUNTER, last)
#define KYOPRO_REP2(i, last) for (auto i = std::decay_t<decltype(last)>(), KYOPRO_LAST = (last); (i) < (KYOPRO_LAST); ++(i))
#define KYOPRO_REP3(i, first, last) for (auto i = (first), KYOPRO_LAST = last; (i) < (KYOPRO_LAST); ++(i))
#define rep(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__ __VA_OPT__(,) KYOPRO_REP4, KYOPRO_REP3, KYOPRO_REP2, KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)

#define KYOPRO_MATCH1(_1) break; case _1:
#define KYOPRO_MATCH2(_1, _2) break; case _1: case _2:
#define KYOPRO_MATCH3(_1, _2, _3) break; case _1: case _2: case _3:
#define KYOPRO_MATCH4(_1, _2, _3, _4) break; case _1: case _2: case _3: case _4:
#define match(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__, KYOPRO_MATCH4, KYOPRO_MATCH3, KYOPRO_MATCH2, KYOPRO_MATCH1)(__VA_ARGS__)
#define otherwise break; default:

#define KYOPRO_LAMBDA1(value) ([&]() noexcept { return (value);})
#define KYOPRO_LAMBDA2(_1, value) ([&](auto&& _1) noexcept { return (value); })
#define KYOPRO_LAMBDA3(_1, _2, value) ([&](auto&& _1, auto&& _2) noexcept { return (value); })
#define KYOPRO_LAMBDA4(_1, _2, _3, value) ([&](auto&& _1, auto&& _2, auto&& _3) noexcept { return (value); })
#define lambda(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__, KYOPRO_LAMBDA4, KYOPRO_LAMBDA3, KYOPRO_LAMBDA2, KYOPRO_LAMBDA1)(__VA_ARGS__)

#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
#line 4 "template/make_array.hpp"

namespace kyopro {
  template<class T>
  constexpr auto make_array(const T& init = T()) noexcept { return init; }

  template<class T, KYOPRO_BASE_UINT length, KYOPRO_BASE_UINT... lengths>
  constexpr auto make_array(const T& init = T()) noexcept {
    auto elm = make_array<T, lengths...>(init);
    std::array<decltype(elm), length> res;
    for (auto& i: res) i = elm;
    return res;
  }
}
#line 6 "template/make_vector.hpp"

namespace kyopro {
  template<KYOPRO_BASE_UINT idx = 0, KYOPRO_BASE_UINT n, class T>
  auto make_vector(const KYOPRO_BASE_UINT (&d)[n], T&& init) noexcept {
    if constexpr (idx < n) return std::vector(d[idx], make_vector<idx + 1>(d, std::forward<T>(init)));
    else return init;
  }

  template<class T, KYOPRO_BASE_UINT idx = 0, KYOPRO_BASE_UINT n>
  auto make_vector(const KYOPRO_BASE_UINT (&d)[n], const T& init = T()) noexcept {
    if constexpr (idx < n) return std::vector(d[idx], make_vector<idx + 1>(d, init));
    else return init;
  }
}
#line 4 "template/min_max_different_types.hpp"

using std::min, std::max;

template<class T, class U, std::enable_if_t<!std::is_same_v<T, U>>* = nullptr>
constexpr std::common_type_t<T, U> min(const T& a, const U& b) noexcept {
  return a < b ? a : b;
}

template<class T, class U, std::enable_if_t<!std::is_same_v<T, U>>* = nullptr>
constexpr std::common_type_t<T, U> max(const T& a, const U& b) noexcept {
  return a > b ? a : b;
}
#line 4 "all.hpp"

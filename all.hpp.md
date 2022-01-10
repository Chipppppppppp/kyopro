---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: base/Hash.hpp
    title: base/Hash.hpp
  - icon: ':warning:'
    path: base/all.hpp
    title: base/all.hpp
  - icon: ':heavy_check_mark:'
    path: base/constant.hpp
    title: base/constant.hpp
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':warning:'
    path: base/trait.hpp
    title: base/trait.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  - icon: ':warning:'
    path: math/div.hpp
    title: math/div.hpp
  - icon: ':warning:'
    path: math/divisors.hpp
    title: math/divisors.hpp
  - icon: ':warning:'
    path: math/euler_phi.hpp
    title: math/euler_phi.hpp
  - icon: ':warning:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':warning:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: math/mod.hpp
    title: math/mod.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid.hpp
    title: math/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':heavy_check_mark:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':heavy_check_mark:'
    path: structure/UnionFind.hpp
    title: structure/UnionFind.hpp
  - icon: ':warning:'
    path: structure/all.hpp
    title: structure/all.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"base/settings.hpp\"\n#include <cstdint>\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::size_t\n#endif\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT\
    \ double\n#endif\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD 1000000007\n\
    #endif\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION 12\n\
    #endif\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV 3\n#endif\n#line 3 \"base/constant.hpp\"\
    \n#include <limits>\n#include <array>\n#include <utility>\n#line 4 \"math/power.hpp\"\
    \nnamespace kyopro {\n  template<class KyoproT>\n  constexpr KyoproT power(KyoproT\
    \ a, std::uint64_t n, KyoproT init = 1) noexcept {\n    while (n > 0) {\n    \
    \  if (n & 1) init *= a;\n      a *= a;\n      n >>= 1;\n    }\n    return init;\n\
    \  }\n}\n#line 8 \"base/constant.hpp\"\n\nnamespace kyopro {\n  inline constexpr\
    \ std::uint64_t kyopro_decimal_max = power(static_cast<std::uint64_t>(10), KYOPRO_DECIMAL_PRECISION);\n\
    \  template<class KyoproT>\n  inline constexpr KyoproT MOD = KYOPRO_DEFAULT_MOD;\n\
    \  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n  template<class\
    \ KyoproT>\n  inline constexpr KyoproT INF = std::numeric_limits<KyoproT>::max()\
    \ / KYOPRO_INF_DIV;\n  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\
    \  template<class KyoproT>\n  inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<KyoproT>(1)\
    \ / kyopro_decimal_max;\n  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\
    \  template<class KyoproT>\n  inline constexpr KyoproT PI = 3.14159265358979323846;\n\
    \  inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n  inline constexpr\
    \ std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{1, 0}, {0,\
    \ 1}, {-1, 0}, {0, -1}}};\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1,\
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 3 \"base/trait.hpp\"\n#include <type_traits>\n\
    #include <iterator>\n#include <stack>\n#include <queue>\n\nnamespace kyopro {\n\
    \  template<class KyoproT, class = void>\n  struct is_iterator: std::false_type\
    \ {};\n  template<class KyoproT>\n  struct is_iterator<KyoproT, std::enable_if_t<!std::is_same_v<typename\
    \ std::iterator_traits<KyoproT>::value_type, void>>>: std::true_type {};\n  template<class\
    \ KyoproT>\n  constexpr bool is_iterator_v = is_iterator<KyoproT>::value;\n\n\
    \  template<class KyoproT, class = void>\n  struct is_container: std::false_type\
    \ {};\n  template<class KyoproT>\n  struct is_container<KyoproT, std::void_t<decltype(std::begin(std::declval<KyoproT>()),\
    \ std::end(std::declval<KyoproT>()), std::empty(std::declval<KyoproT>()))>>: std::true_type\
    \ {};\n  template<class KyoproT>\n  constexpr bool is_container_v = is_container<KyoproT>::value;\n\
    \n  template<class KyoproT>\n  struct is_tuple: std::false_type {};\n  template<class\
    \ KyoproT, class U>\n  struct is_tuple<std::pair<KyoproT, U>>: std::true_type\
    \ {};\n  template<class... Args>\n  struct is_tuple<std::tuple<Args...>>: std::true_type\
    \ {};\n  template<class KyoproT>\n  constexpr bool is_tuple_v = is_tuple<KyoproT>::value;\n\
    \n  template<class KyoproT>\n  struct is_iterable: is_container<KyoproT> {};\n\
    \  template<class KyoproT, class Container>\n  struct is_iterable<std::stack<KyoproT,\
    \ Container>>: std::false_type {};\n  template<class KyoproT, class Container>\n\
    \  struct is_iterable<std::queue<KyoproT, Container>>: std::false_type {};\n \
    \ template<class KyoproT, class Container, class Compare>\n  struct is_iterable<std::priority_queue<KyoproT,\
    \ Container, Compare>>: std::false_type {};\n  template<class KyoproT>\n  constexpr\
    \ bool is_iterable_v = is_iterable<KyoproT>::value;\n}\n#line 3 \"base/Hash.hpp\"\
    \n#include <tuple>\n#line 4 \"math/ModInt.hpp\"\n#include <cassert>\n#line 4 \"\
    math/mod.hpp\"\n\nnamespace kyopro {\n  template<class KyoproT, class KyoproU>\n\
    \  constexpr KyoproT floor_mod(KyoproT kyopro_x, KyoproU kyopro_m) noexcept {\n\
    \    static_assert(std::is_integral_v<KyoproT> && std::is_integral_v<KyoproU>);\n\
    \    if constexpr (std::is_unsigned_v<KyoproT>) return kyopro_x % kyopro_m;\n\
    \    return (kyopro_x %= kyopro_m) < 0 ? kyopro_x + kyopro_m : kyopro_x;\n  }\n\
    \n  template<class KyoproT, class KyoproU>\n  constexpr KyoproT ceil_mod(KyoproT\
    \ kyopro_x, KyoproU kyopro_m) noexcept { return kyopro_m - floor_mod(kyopro_x\
    \ - 1, kyopro_m) - 1; }\n}\n#line 8 \"math/ModInt.hpp\"\n\nnamespace kyopro {\n\
    \  template<std::uint64_t m>\n  struct ModInt {\n    static constexpr std::uint64_t\
    \ mod = m;\n    std::uint64_t value;\n    constexpr ModInt() noexcept = default;\n\
    \    template<class T>\n    constexpr ModInt(T value) noexcept: value(floor_mod(value,\
    \ m)) { static_assert(std::is_integral_v<T>); }\n    template<class T>\n    explicit\
    \ constexpr operator T() const noexcept { return value; }\n    static constexpr\
    \ ModInt raw(std::uint64_t n) noexcept {\n      ModInt res;\n      res.value =\
    \ n;\n      return res;\n    }\n    constexpr ModInt power(std::uint64_t n) const\
    \ noexcept {\n      std::uint64_t res = 1, a = value;\n      while (n > 0) {\n\
    \        if (n & 1) res = res * a % m;\n        a = a * a % m;\n        n >>=\
    \ 1;\n      }\n      return res;\n    }\n    constexpr ModInt inv() const noexcept\
    \ {\n      std::uint64_t a = value, b = m;\n      std::int64_t u = 1, v = 0;\n\
    \      while (b > 0) {\n        std::uint64_t t = a / b;\n        a -= t * b;\n\
    \        std::swap(a, b);\n        u -= t * v;\n        std::swap(u, v);\n   \
    \   }\n      return floor_mod(u, m);\n    }\n    constexpr ModInt operator +()\
    \ const noexcept { return *this; }\n    constexpr ModInt operator -() const noexcept\
    \ { return m - value; }\n    constexpr ModInt& operator ++() noexcept {\n    \
    \  if (++value >= m) value -= m;\n      return *this;\n    }\n    constexpr ModInt\
    \ operator ++(int) noexcept {\n      ModInt before = *this;\n      operator ++();\n\
    \      return before;\n    }\n    constexpr ModInt& operator --() noexcept {\n\
    \      if (value == 0) value = m;\n      --value;\n      return *this;\n    }\n\
    \    constexpr ModInt operator --(int) noexcept {\n      ModInt before = *this;\n\
    \      operator --();\n      return before;\n    }\n    constexpr ModInt& operator\
    \ +=(ModInt rhs) noexcept {\n      if ((value += rhs.value) >= m) value -= m;\n\
    \      return *this;\n    }\n    constexpr ModInt& operator -=(ModInt rhs) noexcept\
    \ {\n      if (value < rhs.value) value += m;\n      value -= rhs.value;\n   \
    \   return *this;\n    }\n    constexpr ModInt& operator *=(ModInt rhs) noexcept\
    \ {\n      value = value * rhs.value % m;\n      return *this;\n    }\n    constexpr\
    \ ModInt& operator /=(ModInt rhs) noexcept {\n      value = value * rhs.inv().value\
    \ % m;\n      return *this;\n    }\n    friend constexpr ModInt operator +(ModInt\
    \ lhs, ModInt rhs) noexcept { return lhs += rhs; }\n    friend constexpr ModInt\
    \ operator -(ModInt lhs, ModInt rhs) noexcept { return lhs -= rhs; }\n    friend\
    \ constexpr ModInt operator *(ModInt lhs, ModInt rhs) noexcept { return lhs *=\
    \ rhs; }\n    friend constexpr ModInt operator /(ModInt lhs, ModInt rhs) noexcept\
    \ { return lhs /= rhs; }\n    friend constexpr bool operator ==(ModInt lhs, ModInt\
    \ rhs) noexcept { return lhs.value == rhs.value; }\n    friend constexpr bool\
    \ operator !=(ModInt lhs, ModInt rhs) noexcept { return lhs.value != rhs.value;\
    \ }\n  };\n  constexpr ModInt<mod> operator \"\" _m(unsigned long long a) noexcept\
    \ { return a; }\n}\n#line 7 \"base/Hash.hpp\"\n\nnamespace kyopro {\n  template<class,\
    \ class = void>\n  struct Hash;\n\n  template<class KyoproT>\n  struct Hash<KyoproT,\
    \ std::enable_if_t<std::is_integral_v<KyoproT>>> { constexpr KYOPRO_BASE_UINT\
    \ operator ()(KyoproT kyopro_a) const noexcept { return kyopro_a; } };\n\n  template<class\
    \ KyoproT>\n  struct Hash<KyoproT, std::enable_if_t<std::is_floating_point_v<KyoproT>>>\
    \ { constexpr KYOPRO_BASE_UINT operator ()(KyoproT kyopro_a) const noexcept {\
    \ return (KYOPRO_BASE_UINT)kyopro_a & 0xfffff000; } };\n\n  template<KYOPRO_BASE_UINT\
    \ m>\n  struct Hash<ModInt<m>> { constexpr KYOPRO_BASE_UINT operator ()(ModInt<m>\
    \ kyopro_a) const noexcept { return kyopro_a; } };\n\n  template<class KyoproT>\n\
    \  struct Hash<KyoproT, std::enable_if_t<is_tuple_v<KyoproT>>> {\n    template<KYOPRO_BASE_UINT\
    \ kyopro_i = 0>\n    constexpr KYOPRO_BASE_UINT operator ()(const KyoproT& kyopro_a)\
    \ const noexcept {\n      if constexpr (kyopro_i == std::tuple_size_v<KyoproT>)\
    \ return std::tuple_size_v<KyoproT>;\n      else {\n        KYOPRO_BASE_UINT kyopro_seed\
    \ = operator()<kyopro_i + 1>(kyopro_a);\n        return kyopro_seed ^ (Hash<std::tuple_element_t<kyopro_i,\
    \ KyoproT>>()(get<kyopro_i>(kyopro_a)) + 0x9e3779b97f4a7c15LU + (kyopro_seed <<\
    \ 12) + (kyopro_seed >> 4));\n      }\n    }\n  };\n\n  template<class KyoproT>\n\
    \  struct Hash<KyoproT, std::enable_if_t<is_container_v<KyoproT>>> {\n  private:\n\
    \    [[no_unique_address]] Hash<typename KyoproT::value_type> make_hash;\n  public:\n\
    \    constexpr KYOPRO_BASE_UINT operator ()(const KyoproT& kyopro_a) const noexcept\
    \ {\n      KYOPRO_BASE_UINT kyopro_seed = kyopro_a.size();\n      for (auto& kyopro_i:\
    \ kyopro_a) kyopro_seed ^= make_hash(kyopro_i) + 0x9e3779b97f4a7c15LU + (kyopro_seed\
    \ << 12) + (kyopro_seed >> 4);\n      return kyopro_seed;\n    }\n  };\n}\n#line\
    \ 3 \"math/div.hpp\"\n\nnamespace kyopro {\n  template<class KyoproT, class KyoproU>\n\
    \  constexpr KyoproT floor_div(KyoproT kyopro_x, KyoproU kyopro_m) noexcept {\n\
    \    static_assert(std::is_integral_v<KyoproT> && std::is_integral_v<KyoproU>);\n\
    \    if constexpr (std::is_unsigned_v<KyoproT>) return kyopro_x / kyopro_m;\n\
    \    if (kyopro_m < 0) return -kyopro_x / -kyopro_m;\n    if (kyopro_x < 0) return\
    \ (kyopro_x + 1) / kyopro_m - 1;\n    return kyopro_x / kyopro_m;\n  }\n\n  template<class\
    \ KyoproT, class KyoproU>\n  constexpr KyoproT ceil_div(KyoproT kyopro_x, KyoproU\
    \ kyopro_m) noexcept { return floor_div(kyopro_x + kyopro_m - 1, kyopro_m); }\n\
    }\n#line 4 \"math/monoid.hpp\"\n\nnamespace kyopro {\n  template<class KyoproT,\
    \ KyoproT kyopro_id = 0>\n  struct Plus {\n    static constexpr KyoproT id = kyopro_id;\n\
    \    static constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept\
    \ { return kyopro_a + kyopro_b; }\n    static constexpr KyoproT inv(KyoproT kyopro_a)\
    \ noexcept { return -kyopro_a; }\n  };\n  template<class KyoproT, KyoproT kyopro_id\
    \ = 1>\n  struct Mul {\n    static constexpr KyoproT id = kyopro_id;\n    static\
    \ constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a\
    \ * kyopro_b; }\n    static constexpr KyoproT inv(KyoproT kyopro_a) noexcept {\n\
    \      static_assert(!std::is_integral_v<KyoproT>);\n      return 1 / kyopro_a;\n\
    \    }\n  };\n  template<class KyoproT, KyoproT kyopro_id = -inf>\n  struct Max\
    \ {\n    static constexpr KyoproT id = kyopro_id;\n    static constexpr KyoproT\
    \ op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a > kyopro_b\
    \ ? kyopro_a : kyopro_b; }\n  };\n  template<class KyoproT, KyoproT kyopro_id\
    \ = inf>\n  struct Min {\n    static constexpr KyoproT id = kyopro_id;\n    static\
    \ constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a\
    \ < kyopro_b ? kyopro_a : kyopro_b; }\n  };\n}\n#line 3 \"math/is_prime.hpp\"\n\
    \nnamespace kyopro {\n  constexpr bool is_prime(std::uint64_t kyopro_n) noexcept\
    \ {\n    if (kyopro_n < 2) return false;\n    if (kyopro_n < 4) return true;\n\
    \    if ((kyopro_n & 1) == 0 || kyopro_n % 3 == 0) return false;\n    for (std::uint64_t\
    \ kyopro_i = 5; kyopro_i * kyopro_i <= kyopro_n; kyopro_i += 4) {\n      if (kyopro_n\
    \ % kyopro_i == 0) return false;\n      if (kyopro_n % (kyopro_i += 2) == 0) return\
    \ false;\n    }\n    return true;\n  }\n}\n#line 3 \"math/divisors.hpp\"\n#include\
    \ <vector>\n#line 5 \"math/divisors.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ KyoproContainer = std::vector<KYOPRO_BASE_INT>>\n  KyoproContainer divisors(std::uint64_t\
    \ kyopro_n) {\n    KyoproContainer kyopro_lower, kyopro_upper;\n    std::uint64_t\
    \ kyopro_i;\n    for (kyopro_i = 1; kyopro_i * kyopro_i < kyopro_n; ++kyopro_i)\
    \ if (kyopro_n % kyopro_i == 0) {\n      kyopro_lower.emplace_back(kyopro_i);\n\
    \      kyopro_upper.emplace_back(kyopro_n / kyopro_i);\n    }\n    if (kyopro_i\
    \ * kyopro_i == kyopro_n) kyopro_lower.emplace_back(kyopro_i);\n    kyopro_lower.insert(end(kyopro_lower),\
    \ rall(kyopro_upper));\n    return kyopro_lower;\n  }\n}\n#line 6 \"math/factorize.hpp\"\
    \n\nnamespace kyopro {\n  template<class KyoproContainer = std::vector<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>>>\n  KyoproContainer factorize(size_t kyopro_n) {\n    KyoproContainer\
    \ kyopro_res;\n    if ((kyopro_n & 1) == 0) {\n      kyopro_res.emplace_back(2,\
    \ 1);\n      kyopro_n >>= 1;\n      while ((kyopro_n & 1) == 0) {\n        ++kyopro_res.back().second;\n\
    \        kyopro_n >>= 1;\n      }\n    }\n    for (size_t kyopro_i = 3; kyopro_i\
    \ * kyopro_i <= kyopro_n; kyopro_i += 2) if (kyopro_n % kyopro_i == 0) {\n   \
    \   kyopro_res.emplace_back(2, 1);\n      kyopro_n /= kyopro_i;\n      while (kyopro_n\
    \ % kyopro_i == 0) {\n        ++kyopro_res.back().second;\n        kyopro_n /=\
    \ kyopro_i;\n      }\n    }\n    if (kyopro_n != 1) kyopro_res.emplace_back(kyopro_n,\
    \ 1);\n    return kyopro_res;\n  }\n}\n#line 3 \"math/euler_phi.hpp\"\n\nnamespace\
    \ kyopro {\n  constexpr std::uint64_t euler_phi(std::uint64_t kyopro_n) noexcept\
    \ {\n    std::uint64_t kyopro_res = kyopro_n;\n    if ((kyopro_n & 1) == 0) {\n\
    \      kyopro_res -= kyopro_res >> 1;\n      kyopro_n >>= 1;\n      while ((kyopro_n\
    \ & 1) == 0) kyopro_n >>= 1;\n    }\n    for (std::uint64_t kyopro_i = 3; kyopro_i\
    \ * kyopro_i <= kyopro_n; kyopro_i += 2) {\n      if (kyopro_n % kyopro_i == 0)\
    \ {\n        kyopro_res -= kyopro_res / kyopro_i;\n        kyopro_n /= kyopro_i;\n\
    \        while (kyopro_n % kyopro_i == 0) kyopro_n /= kyopro_i;\n      }\n   \
    \ }\n    if (kyopro_n != 1) kyopro_res -= kyopro_res / kyopro_n;\n    return kyopro_res;\n\
    \  }\n}\n#line 2 \"structure/UnionFind.hpp\"\n/* UnionFind */\n#line 4 \"structure/UnionFind.hpp\"\
    \n#include <unordered_map>\n#include <algorithm>\n#line 7 \"structure/UnionFind.hpp\"\
    \n\nnamespace kyopro {\n  template<class KyoproContainer = std::vector<int>>\n\
    \  struct UnionFind {\n  private:\n    KyoproContainer kyopro_par;\n  public:\n\
    \    UnionFind() noexcept = default;\n    UnionFind(KYOPRO_BASE_UINT kyopro_n)\
    \ noexcept: kyopro_par(kyopro_n, -1) {}\n    void resize(KYOPRO_BASE_UINT kyopro_x)\
    \ { kyopro_par.resize(kyopro_x, -1); }\n    void assign(KYOPRO_BASE_UINT kyopro_x)\
    \ { kyopro_par.assign(kyopro_x, -1); }\n    void reset() { std::fill(std::begin(kyopro_par),\
    \ std::end(kyopro_par), -1); }\n    KYOPRO_BASE_UINT size() const noexcept { return\
    \ kyopro_par.size(); }\n    KYOPRO_BASE_INT find(int kyopro_x) {\n      int kyopro_p\
    \ = kyopro_x;\n      while (kyopro_par[kyopro_p] >= 0) kyopro_p = kyopro_par[kyopro_p];\n\
    \      while (kyopro_x != kyopro_p) {\n        int kyopro_tmp = kyopro_x;\n  \
    \      kyopro_x = kyopro_par[kyopro_x];\n        kyopro_par[kyopro_tmp] = kyopro_p;\n\
    \      }\n      return kyopro_p;\n    }\n    bool unite(int kyopro_x, int kyopro_y)\
    \ {\n      kyopro_x = find(kyopro_x), kyopro_y = find(kyopro_y);\n      if (kyopro_x\
    \ == kyopro_y) return false;\n      if (kyopro_par[kyopro_x] > kyopro_par[kyopro_y])\
    \ {\n        int kyopro_tmp = kyopro_x;\n        kyopro_x = kyopro_y;\n      \
    \  kyopro_y = kyopro_tmp;\n      }\n      kyopro_par[kyopro_x] += kyopro_par[kyopro_y];\n\
    \      kyopro_par[kyopro_y] = kyopro_x;\n      return true;\n    }\n    bool same(int\
    \ kyopro_x, int kyopro_y) { return find(kyopro_x) == find(kyopro_y); }\n    KYOPRO_BASE_INT\
    \ group_size(int kyopro_x) { return -kyopro_par[find(kyopro_x)]; }\n    KyoproContainer\
    \ group_members(int kyopro_x) {\n      kyopro_x = find(kyopro_x);\n      KyoproContainer\
    \ kyopro_a;\n      for (int kyopro_i = 0; kyopro_i < (int)(size()); ++kyopro_i)\
    \ if (find(kyopro_i) == kyopro_x) kyopro_a.emplace_back(kyopro_i);\n      return\
    \ kyopro_a;\n    }\n    template<class KyoproVector = std::vector<KYOPRO_BASE_INT>>\n\
    \    KyoproVector roots() const {\n      KyoproVector kyopro_a;\n      for (int\
    \ kyopro_i = 0; kyopro_i < (int)(size()); ++kyopro_i) if (kyopro_par[kyopro_i]\
    \ < 0) kyopro_a.emplace_back(kyopro_i);\n      return kyopro_a;\n    }\n    KYOPRO_BASE_INT\
    \ group_count() const {\n      KYOPRO_BASE_INT kyopro_cnt = 0;\n      for (int\
    \ kyopro_i = 0; kyopro_i < (int)(size()); ++kyopro_i) if (kyopro_par[kyopro_i]\
    \ < 0) ++kyopro_cnt;\n      return kyopro_cnt;\n    }\n    template<class KyoproMap\
    \ = std::unordered_map<KYOPRO_BASE_INT, std::vector<KYOPRO_BASE_INT>>>\n    KyoproMap\
    \ all_group_members() {\n      KyoproMap kyopro_group_members;\n      for (int\
    \ kyopro_member = 0; kyopro_member < (int)(size()); ++kyopro_member) kyopro_group_members[find(kyopro_member)].emplace_back(kyopro_member);\n\
    \      return kyopro_group_members;\n    }\n  };\n}\n#line 2 \"structure/FenwickTree.hpp\"\
    \n/* FenwickTree */\n#line 7 \"structure/FenwickTree.hpp\"\n\nnamespace kyopro\
    \ {\n  template<class KyoproT, class KyoproOp = Plus<KyoproT>, class KyoproContainer\
    \ = std::vector<KyoproT>>\n  struct FenwickTree {\n  private:\n    KyoproContainer\
    \ kyopro_tree;\n  public:\n    using value_type = KyoproT;\n    using size_type\
    \ = KYOPRO_BASE_UINT;\n    using reference = KyoproT&;\n    using const_reference\
    \ = const KyoproT&;\n    FenwickTree() noexcept = default;\n    FenwickTree(KYOPRO_BASE_UINT\
    \ kyopro_n) noexcept: kyopro_tree(kyopro_n, KyoproOp::id) {}\n    KYOPRO_BASE_UINT\
    \ size() noexcept { return kyopro_tree.size(); }\n    void apply(int kyopro_p,\
    \ const KyoproT& kyopro_x) {\n      ++kyopro_p;\n      while (kyopro_p <= (int)size())\
    \ {\n        kyopro_tree[kyopro_p - 1] = KyoproOp::op(kyopro_tree[kyopro_p - 1],\
    \ kyopro_x);\n        kyopro_p += kyopro_p & -kyopro_p;\n      }\n    }\n    KyoproT\
    \ prod(int kyopro_r) const {\n      KyoproT kyopro_s = KyoproOp::id;\n      while\
    \ (kyopro_r > 0) {\n        kyopro_s = KyoproOp::op(kyopro_s, kyopro_tree[kyopro_r\
    \ - 1]);\n        kyopro_r -= kyopro_r & -kyopro_r;\n      }\n      return kyopro_s;\n\
    \    }\n    KyoproT prod(int kyopro_l, int kyopro_r) const { return KyoproOp::op(prod(kyopro_r),\
    \ KyoproOp::inv(prod(kyopro_l))); }\n    KyoproT get(int kyopro_p) { return KyoproOp::op(prod(kyopro_p\
    \ + 1), KyoproOp::inv(prod(kyopro_p))); }\n    KyoproT all_query() { return prod(kyopro_tree.size());\
    \ }\n    void set(int kyopro_p, const KyoproT& kyopro_x) { apply(kyopro_p, KyoproOp::op(kyopro_x,\
    \ KyoproOp::inv(get(kyopro_p)))); }\n  };\n}\n#line 4 \"template/alias.hpp\"\n\
    #include <functional>\n#line 7 \"template/alias.hpp\"\n#include <string>\n#include\
    \ <set>\n#include <map>\n#include <unordered_set>\n#line 16 \"template/alias.hpp\"\
    \n\nnamespace kyopro {\n  using ll = int64_t;\n  using ull = uint64_t;\n  using\
    \ lf = double;\n  #ifdef __SIZEOF_INT128__\n  using i128 = __int128_t;\n  using\
    \ u128 = __uint128_t;\n  #endif\n  #ifdef __SIZEOF_FLOAT128__\n  using f128 =\
    \ __float128;\n  #endif\n\n  template<class T>\n  using vec = std::vector<T>;\n\
    \  using str = std::string;\n  template<class Key>\n  using hash_set = std::unordered_set<Key,\
    \ Hash<Key>>;\n  template<class Key, class T>\n  using hash_map = std::unordered_map<Key,\
    \ T, Hash<Key>>;\n  template<class Key>\n  using hash_multiset = std::unordered_multiset<Key,\
    \ Hash<Key>>;\n  template<class Key, class T>\n  using hash_multimap = std::unordered_multimap<Key,\
    \ T, Hash<Key>>;\n  template<class T, class Compare = std::less<T>, class Container\
    \ = vec<T>>\n  using priq = std::priority_queue<T, Container, Compare>;\n  template<class\
    \ T, class Compare = std::greater<T>, class Container = vec<T>>\n  using heapq\
    \ = priq<T, Container, Compare>;\n\n  using pll = std::pair<ll, ll>;\n  using\
    \ l3 = std::tuple<ll, ll, ll>;\n  using l4 = std::tuple<ll, ll, ll, ll>;\n  using\
    \ l5 = std::tuple<ll, ll, ll, ll, ll>;\n  using mll = std::map<ll, ll>;\n  using\
    \ hmll = hash_map<ll, ll>;\n  using mmll = std::multimap<ll, ll>;\n  using hmmll\
    \ = std::multimap<ll, ll>;\n  using sl = std::set<ll>;\n  using spll = std::set<pll>;\n\
    \  using hsl = hash_set<ll>;\n  using hspll = hash_set<pll>;\n  using msl = std::multiset<ll>;\n\
    \  using mspll = std::multiset<pll>;\n  using hmsl = hash_multiset<ll>;\n  using\
    \ hmspll = hash_multiset<pll>;\n  using dql = std::deque<ll>;\n  using dqpll =\
    \ std::deque<pll>;\n  using quel = std::queue<ll>;\n  using quepll = std::queue<pll>;\n\
    \  using stkl = std::stack<ll>;\n  using stkpll = std::stack<pll>;\n  using pql\
    \ = priq<ll>;\n  using pqpll = priq<pll>;\n  using hql = heapq<ll>;\n  using hqpll\
    \ = heapq<pll>;\n  using vl = vec<ll>;\n  using vvl = vec<vl>;\n  using vvvl =\
    \ vec<vvl>;\n  using vi = vec<int>;\n  using vvi = vec<vi>;\n  using vvvi = vec<vvi>;\n\
    \  using vf = vec<lf>;\n  using vvf = vec<vf>;\n  using vvvf = vec<vvf>;\n  using\
    \ vb = vec<char>;\n  using vvb = vec<vb>;\n  using vvvb = vec<vvb>;\n  using vc\
    \ = vec<char>;\n  using vvc = vec<vc>;\n  using vvvc = vec<vvc>;\n  using vs =\
    \ vec<str>;\n  using vvs = vec<vs>;\n  using vvvs = vec<vvs>;\n  using vpll =\
    \ vec<pll>;\n  using vvpll = vec<vpll>;\n  using vvvpll = vec<vvpll>;\n  using\
    \ vsl = vec<sl>;\n  using vhsl = vec<hsl>;\n  using vmll = vec<mll>;\n  using\
    \ vhmll = vec<hmll>;\n  using mint = ModInt<mod>;\n  using vm = vec<mint>;\n \
    \ using vvm = vec<vm>;\n  using vvvm = vec<vvm>;\n}\n\nusing namespace std;\n\
    using namespace kyopro;\n#line 6 \"all.hpp\"\n"
  code: '#pragma once

    #include "base/all.hpp"

    #include "math/all.hpp"

    #include "structure/all.hpp"

    #include "template/all.hpp"'
  dependsOn:
  - base/all.hpp
  - base/settings.hpp
  - base/constant.hpp
  - math/power.hpp
  - base/trait.hpp
  - base/Hash.hpp
  - math/ModInt.hpp
  - math/mod.hpp
  - math/all.hpp
  - math/div.hpp
  - math/monoid.hpp
  - math/is_prime.hpp
  - math/divisors.hpp
  - math/factorize.hpp
  - math/euler_phi.hpp
  - structure/all.hpp
  - structure/UnionFind.hpp
  - structure/FenwickTree.hpp
  - template/all.hpp
  - template/alias.hpp
  isVerificationFile: false
  path: all.hpp
  requiredBy: []
  timestamp: '2022-01-10 20:01:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: all.hpp
layout: document
redirect_from:
- /library/all.hpp
- /library/all.hpp.html
title: all.hpp
---

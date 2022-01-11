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
  bundledCode: "#line 2 \"base/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::size_t\n#endif\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT\
    \ double\n#endif\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD 1000000007\n\
    #endif\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION 12\n\
    #endif\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV 3\n#endif\n#line 3 \"base/constant.hpp\"\
    \n#include <limits>\n#include <array>\n#include <utility>\n#line 4 \"math/power.hpp\"\
    \nnamespace kyopro {\n  template<class _typeT>\n  constexpr _typeT power(_typeT\
    \ a, std::uint64_t n, _typeT init = 1) noexcept {\n    while (n > 0) {\n     \
    \ if (n & 1) init *= a;\n      a *= a;\n      n >>= 1;\n    }\n    return init;\n\
    \  }\n}\n#line 8 \"base/constant.hpp\"\n\nnamespace kyopro {\n  inline constexpr\
    \ std::uint64_t _decimal_max = power(static_cast<std::uint64_t>(10), KYOPRO_DECIMAL_PRECISION);\n\
    \  template<class _typeT>\n  inline constexpr _typeT MOD = KYOPRO_DEFAULT_MOD;\n\
    \  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n  template<class\
    \ _typeT>\n  inline constexpr _typeT INF = std::numeric_limits<_typeT>::max()\
    \ / KYOPRO_INF_DIV;\n  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\
    \  template<class _typeT>\n  inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<_typeT>(1)\
    \ / _decimal_max;\n  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\
    \  template<class _typeT>\n  inline constexpr _typeT PI = 3.14159265358979323846;\n\
    \  inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n  inline constexpr\
    \ std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{1, 0}, {0,\
    \ 1}, {-1, 0}, {0, -1}}};\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1,\
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 3 \"base/trait.hpp\"\n#include <type_traits>\n\
    #include <iterator>\n#include <stack>\n#include <queue>\n\n#ifdef __SIZEOF_INT128__\n\
    struct std::is_integral<__int128_t>: std::true_type {};\nstruct std::is_signed<__int128_t>:\
    \ std::true_type {};\nstruct std::is_integral<__uint128_t>: std::true_type {};\n\
    struct std::is_unsigned<__uint128_t>: std::true_type {};\n#endif\n#ifdef __SIZEOF_FLOAT128__\n\
    struct std::is_floating_point<__float128>: std::true_type {};\n#endif\n\nnamespace\
    \ kyopro {\n  template<class _typeT, class = void>\n  struct is_iterator: std::false_type\
    \ {};\n  template<class _typeT>\n  struct is_iterator<_typeT, std::enable_if_t<!std::is_same_v<typename\
    \ std::iterator_traits<_typeT>::value_type, void>>>: std::true_type {};\n  template<class\
    \ _typeT>\n  constexpr bool is_iterator_v = is_iterator<_typeT>::value;\n\n  template<class\
    \ _typeT, class = void>\n  struct is_container: std::false_type {};\n  template<class\
    \ _typeT>\n  struct is_container<_typeT, std::void_t<decltype(std::begin(std::declval<_typeT>()),\
    \ std::end(std::declval<_typeT>()), std::empty(std::declval<_typeT>()))>>: std::true_type\
    \ {};\n  template<class _typeT>\n  constexpr bool is_container_v = is_container<_typeT>::value;\n\
    \n  template<class _typeT>\n  struct is_tuple: std::false_type {};\n  template<class\
    \ _typeT, class U>\n  struct is_tuple<std::pair<_typeT, U>>: std::true_type {};\n\
    \  template<class... Args>\n  struct is_tuple<std::tuple<Args...>>: std::true_type\
    \ {};\n  template<class _typeT>\n  constexpr bool is_tuple_v = is_tuple<_typeT>::value;\n\
    \n  template<class _typeT>\n  struct is_iterable: is_container<_typeT> {};\n \
    \ template<class _typeT, class Container>\n  struct is_iterable<std::stack<_typeT,\
    \ Container>>: std::false_type {};\n  template<class _typeT, class Container>\n\
    \  struct is_iterable<std::queue<_typeT, Container>>: std::false_type {};\n  template<class\
    \ _typeT, class Container, class Compare>\n  struct is_iterable<std::priority_queue<_typeT,\
    \ Container, Compare>>: std::false_type {};\n  template<class _typeT>\n  constexpr\
    \ bool is_iterable_v = is_iterable<_typeT>::value;\n}\n#line 3 \"base/Hash.hpp\"\
    \n#include <tuple>\n#line 6 \"base/Hash.hpp\"\n\nnamespace kyopro {\n  template<class,\
    \ class = void>\n  struct Hash;\n\n  template<class _typeT>\n  struct Hash<_typeT,\
    \ std::enable_if_t<std::is_integral_v<_typeT>>> { constexpr KYOPRO_BASE_UINT operator\
    \ ()(_typeT _a) const noexcept { return _a; } };\n\n  template<class _typeT>\n\
    \  struct Hash<_typeT, std::enable_if_t<std::is_floating_point_v<_typeT>>> { constexpr\
    \ KYOPRO_BASE_UINT operator ()(_typeT _a) const noexcept { return (KYOPRO_BASE_UINT)_a\
    \ & 0xfffff000; } };\n\n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<is_tuple_v<_typeT>>>\
    \ {\n    template<KYOPRO_BASE_UINT _i = 0>\n    constexpr KYOPRO_BASE_UINT operator\
    \ ()(const _typeT& _a) const noexcept {\n      if constexpr (_i == std::tuple_size_v<_typeT>)\
    \ return std::tuple_size_v<_typeT>;\n      else {\n        KYOPRO_BASE_UINT _seed\
    \ = operator()<_i + 1>(_a);\n        return _seed ^ (Hash<std::tuple_element_t<_i,\
    \ _typeT>>()(get<_i>(_a)) + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed >> 4));\n\
    \      }\n    }\n  };\n\n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<is_container_v<_typeT>>>\
    \ {\n  private:\n    [[no_unique_address]] Hash<typename _typeT::value_type> make_hash;\n\
    \  public:\n    constexpr KYOPRO_BASE_UINT operator ()(const _typeT& _a) const\
    \ noexcept {\n      KYOPRO_BASE_UINT _seed = _a.size();\n      for (auto& _i:\
    \ _a) _seed ^= make_hash(_i) + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed >>\
    \ 4);\n      return _seed;\n    }\n  };\n}\n#line 3 \"math/div.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class _typeT, class _typeU>\n  constexpr _typeT floor_div(_typeT\
    \ _x, _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>);\n\
    \    if constexpr (std::is_unsigned_v<_typeT>) return _x / _m;\n    if (_m < 0)\
    \ return -_x / -_m;\n    if (_x < 0) return (_x + 1) / _m - 1;\n    return _x\
    \ / _m;\n  }\n\n  template<class _typeT, class _typeU>\n  constexpr _typeT ceil_div(_typeT\
    \ _x, _typeU _m) noexcept { return floor_div(_x + _m - 1, _m); }\n}\n#line 3 \"\
    math/mod.hpp\"\n#include <cassert>\n\nnamespace kyopro {\n  template<class _typeT,\
    \ class _typeU>\n  constexpr _typeT floor_mod(_typeT _x, _typeU _m) noexcept {\n\
    \    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>);\n\
    \    if constexpr (std::is_unsigned_v<_typeT>) return _x % _m;\n    return (_x\
    \ %= _m) < 0 ? _x + _m : _x;\n  }\n\n  template<class _typeT, class _typeU>\n\
    \  constexpr _typeT ceil_mod(_typeT _x, _typeU _m) noexcept { return _m - floor_mod(_x\
    \ - 1, _m) - 1; }\n}\n#line 9 \"math/ModInt.hpp\"\n\nnamespace kyopro {\n  template<std::uint64_t\
    \ m>\n  struct ModInt {\n    static constexpr std::uint64_t mod = m;\n    std::uint64_t\
    \ value;\n    constexpr ModInt() noexcept = default;\n    template<class T>\n\
    \    constexpr ModInt(T value) noexcept: value(floor_mod(value, m)) { static_assert(std::is_integral_v<T>);\
    \ }\n    template<class T>\n    explicit constexpr operator T() const noexcept\
    \ { return value; }\n    static constexpr ModInt raw(std::uint64_t n) noexcept\
    \ {\n      ModInt res;\n      res.value = n;\n      return res;\n    }\n    constexpr\
    \ ModInt power(std::uint64_t n) const noexcept {\n      std::uint64_t res = 1,\
    \ a = value;\n      while (n > 0) {\n        if (n & 1) res = res * a % m;\n \
    \       a = a * a % m;\n        n >>= 1;\n      }\n      return res;\n    }\n\
    \    constexpr ModInt inv() const noexcept {\n      std::uint64_t a = value, b\
    \ = m;\n      std::int64_t u = 1, v = 0;\n      while (b > 0) {\n        std::uint64_t\
    \ t = a / b;\n        a -= t * b;\n        std::swap(a, b);\n        u -= t *\
    \ v;\n        std::swap(u, v);\n      }\n      return floor_mod(u, m);\n    }\n\
    \    constexpr ModInt operator +() const noexcept { return *this; }\n    constexpr\
    \ ModInt operator -() const noexcept { return m - value; }\n    constexpr ModInt&\
    \ operator ++() noexcept {\n      if (++value >= m) value -= m;\n      return\
    \ *this;\n    }\n    constexpr ModInt operator ++(int) noexcept {\n      ModInt\
    \ before = *this;\n      operator ++();\n      return before;\n    }\n    constexpr\
    \ ModInt& operator --() noexcept {\n      if (value == 0) value = m;\n      --value;\n\
    \      return *this;\n    }\n    constexpr ModInt operator --(int) noexcept {\n\
    \      ModInt before = *this;\n      operator --();\n      return before;\n  \
    \  }\n    constexpr ModInt& operator +=(ModInt rhs) noexcept {\n      if ((value\
    \ += rhs.value) >= m) value -= m;\n      return *this;\n    }\n    constexpr ModInt&\
    \ operator -=(ModInt rhs) noexcept {\n      if (value < rhs.value) value += m;\n\
    \      value -= rhs.value;\n      return *this;\n    }\n    constexpr ModInt&\
    \ operator *=(ModInt rhs) noexcept {\n      value = value * rhs.value % m;\n \
    \     return *this;\n    }\n    constexpr ModInt& operator /=(ModInt rhs) noexcept\
    \ {\n      value = value * rhs.inv().value % m;\n      return *this;\n    }\n\
    \    friend constexpr ModInt operator +(ModInt lhs, ModInt rhs) noexcept { return\
    \ lhs += rhs; }\n    friend constexpr ModInt operator -(ModInt lhs, ModInt rhs)\
    \ noexcept { return lhs -= rhs; }\n    friend constexpr ModInt operator *(ModInt\
    \ lhs, ModInt rhs) noexcept { return lhs *= rhs; }\n    friend constexpr ModInt\
    \ operator /(ModInt lhs, ModInt rhs) noexcept { return lhs /= rhs; }\n    friend\
    \ constexpr bool operator ==(ModInt lhs, ModInt rhs) noexcept { return lhs.value\
    \ == rhs.value; }\n    friend constexpr bool operator !=(ModInt lhs, ModInt rhs)\
    \ noexcept { return lhs.value != rhs.value; }\n  };\n\n  template<KYOPRO_BASE_UINT\
    \ m>\n  struct Hash<ModInt<m>> { constexpr KYOPRO_BASE_UINT operator ()(ModInt<m>\
    \ _a) const noexcept { return _a; } };\n\n  constexpr ModInt<mod> operator \"\"\
    \ _m(unsigned long long a) noexcept { return a; }\n}\n#line 4 \"math/monoid.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeT, _typeT _id = 0>\n  struct Plus\
    \ {\n    static constexpr _typeT id = _id;\n    static constexpr _typeT op(_typeT\
    \ _a, _typeT _b) noexcept { return _a + _b; }\n    static constexpr _typeT inv(_typeT\
    \ _a) noexcept { return -_a; }\n  };\n  template<class _typeT, _typeT _id = 1>\n\
    \  struct Mul {\n    static constexpr _typeT id = _id;\n    static constexpr _typeT\
    \ op(_typeT _a, _typeT _b) noexcept { return _a * _b; }\n    static constexpr\
    \ _typeT inv(_typeT _a) noexcept {\n      static_assert(!std::is_integral_v<_typeT>);\n\
    \      return 1 / _a;\n    }\n  };\n  template<class _typeT, _typeT _id = -inf>\n\
    \  struct Max {\n    static constexpr _typeT id = _id;\n    static constexpr _typeT\
    \ op(_typeT _a, _typeT _b) noexcept { return _a > _b ? _a : _b; }\n  };\n  template<class\
    \ _typeT, _typeT _id = inf>\n  struct Min {\n    static constexpr _typeT id =\
    \ _id;\n    static constexpr _typeT op(_typeT _a, _typeT _b) noexcept { return\
    \ _a < _b ? _a : _b; }\n  };\n}\n#line 3 \"math/is_prime.hpp\"\n\nnamespace kyopro\
    \ {\n  constexpr bool is_prime(std::uint64_t _n) noexcept {\n    if (_n < 2) return\
    \ false;\n    if (_n < 4) return true;\n    if ((_n & 1) == 0 || _n % 3 == 0)\
    \ return false;\n    for (std::uint64_t _i = 5; _i * _i <= _n; _i += 4) {\n  \
    \    if (_n % _i == 0) return false;\n      if (_n % (_i += 2) == 0) return false;\n\
    \    }\n    return true;\n  }\n}\n#line 3 \"math/divisors.hpp\"\n#include <vector>\n\
    #line 5 \"math/divisors.hpp\"\n\nnamespace kyopro {\n  template<class _typeContainer\
    \ = std::vector<KYOPRO_BASE_INT>>\n  _typeContainer divisors(std::uint64_t _n)\
    \ {\n    _typeContainer _lower, _upper;\n    std::uint64_t _i;\n    for (_i =\
    \ 1; _i * _i < _n; ++_i) if (_n % _i == 0) {\n      _lower.emplace_back(_i);\n\
    \      _upper.emplace_back(_n / _i);\n    }\n    if (_i * _i == _n) _lower.emplace_back(_i);\n\
    \    _lower.insert(end(_lower), rall(_upper));\n    return _lower;\n  }\n}\n#line\
    \ 6 \"math/factorize.hpp\"\n\nnamespace kyopro {\n  template<class _typeContainer\
    \ = std::vector<KYOPRO_BASE_INT>>\n  _typeContainer factorize(std::uint64_t _n)\
    \ {\n    _typeContainer _res;\n    while ((_n & 1) == 0) {\n      _res.emplace_back(2);\n\
    \      _n >>= 1;\n    }\n    for (std::uint64_t _i = 3; _i * _i <= _n; _i += 2)\
    \ while (_n % _i == 0) {\n      _res.emplace_back(2);\n      _n /= _i;\n    }\n\
    \    if (_n != 1) _res.emplace_back(_n);\n    return _res;\n  }\n}\n#line 3 \"\
    math/euler_phi.hpp\"\n\nnamespace kyopro {\n  constexpr std::uint64_t euler_phi(std::uint64_t\
    \ _n) noexcept {\n    std::uint64_t _res = _n;\n    if ((_n & 1) == 0) {\n   \
    \   _res -= _res >> 1;\n      _n >>= 1;\n      while ((_n & 1) == 0) _n >>= 1;\n\
    \    }\n    for (std::uint64_t _i = 3; _i * _i <= _n; _i += 2) {\n      if (_n\
    \ % _i == 0) {\n        _res -= _res / _i;\n        _n /= _i;\n        while (_n\
    \ % _i == 0) _n /= _i;\n      }\n    }\n    if (_n != 1) _res -= _res / _n;\n\
    \    return _res;\n  }\n}\n#line 2 \"structure/UnionFind.hpp\"\n/* UnionFind */\n\
    #line 4 \"structure/UnionFind.hpp\"\n#include <unordered_map>\n#include <algorithm>\n\
    #line 7 \"structure/UnionFind.hpp\"\n\nnamespace kyopro {\n  template<class _typeContainer\
    \ = std::vector<int>>\n  struct UnionFind {\n  private:\n    _typeContainer _par;\n\
    \  public:\n    UnionFind() noexcept = default;\n    UnionFind(KYOPRO_BASE_UINT\
    \ _n) noexcept: _par(_n, -1) {}\n    void resize(KYOPRO_BASE_UINT _x) { _par.resize(_x,\
    \ -1); }\n    void assign(KYOPRO_BASE_UINT _x) { _par.assign(_x, -1); }\n    void\
    \ reset() { std::fill(std::begin(_par), std::end(_par), -1); }\n    KYOPRO_BASE_UINT\
    \ size() const noexcept { return _par.size(); }\n    KYOPRO_BASE_INT find(int\
    \ _x) {\n      int _p = _x;\n      while (_par[_p] >= 0) _p = _par[_p];\n    \
    \  while (_x != _p) {\n        int _tmp = _x;\n        _x = _par[_x];\n      \
    \  _par[_tmp] = _p;\n      }\n      return _p;\n    }\n    bool unite(int _x,\
    \ int _y) {\n      _x = find(_x), _y = find(_y);\n      if (_x == _y) return false;\n\
    \      if (_par[_x] > _par[_y]) {\n        int _tmp = _x;\n        _x = _y;\n\
    \        _y = _tmp;\n      }\n      _par[_x] += _par[_y];\n      _par[_y] = _x;\n\
    \      return true;\n    }\n    bool same(int _x, int _y) { return find(_x) ==\
    \ find(_y); }\n    KYOPRO_BASE_INT group_size(int _x) { return -_par[find(_x)];\
    \ }\n    _typeContainer group_members(int _x) {\n      _x = find(_x);\n      _typeContainer\
    \ _a;\n      for (int _i = 0; _i < (int)(size()); ++_i) if (find(_i) == _x) _a.emplace_back(_i);\n\
    \      return _a;\n    }\n    template<class _typeVector = std::vector<KYOPRO_BASE_INT>>\n\
    \    _typeVector roots() const {\n      _typeVector _a;\n      for (int _i = 0;\
    \ _i < (int)(size()); ++_i) if (_par[_i] < 0) _a.emplace_back(_i);\n      return\
    \ _a;\n    }\n    KYOPRO_BASE_INT group_count() const {\n      KYOPRO_BASE_INT\
    \ _cnt = 0;\n      for (int _i = 0; _i < (int)(size()); ++_i) if (_par[_i] < 0)\
    \ ++_cnt;\n      return _cnt;\n    }\n    template<class _typeMap = std::unordered_map<KYOPRO_BASE_INT,\
    \ std::vector<KYOPRO_BASE_INT>>>\n    _typeMap all_group_members() {\n      _typeMap\
    \ _group_members;\n      for (int _member = 0; _member < (int)(size()); ++_member)\
    \ _group_members[find(_member)].emplace_back(_member);\n      return _group_members;\n\
    \    }\n  };\n}\n#line 2 \"structure/FenwickTree.hpp\"\n/* FenwickTree */\n#line\
    \ 7 \"structure/FenwickTree.hpp\"\n\nnamespace kyopro {\n  template<class _typeT,\
    \ class _typeOp = Plus<_typeT>, class _typeContainer = std::vector<_typeT>>\n\
    \  struct FenwickTree {\n  private:\n    _typeContainer _tree;\n  public:\n  \
    \  using value_type = _typeT;\n    using size_type = KYOPRO_BASE_UINT;\n    using\
    \ reference = _typeT&;\n    using const_reference = const _typeT&;\n    FenwickTree()\
    \ noexcept = default;\n    FenwickTree(KYOPRO_BASE_UINT _n) noexcept: _tree(_n,\
    \ _typeOp::id) {}\n    KYOPRO_BASE_UINT size() noexcept { return _tree.size();\
    \ }\n    void apply(int _p, const _typeT& _x) {\n      ++_p;\n      while (_p\
    \ <= (int)size()) {\n        _tree[_p - 1] = _typeOp::op(_tree[_p - 1], _x);\n\
    \        _p += _p & -_p;\n      }\n    }\n    _typeT prod(int _r) const {\n  \
    \    _typeT _s = _typeOp::id;\n      while (_r > 0) {\n        _s = _typeOp::op(_s,\
    \ _tree[_r - 1]);\n        _r -= _r & -_r;\n      }\n      return _s;\n    }\n\
    \    _typeT prod(int _l, int _r) const { return _typeOp::op(prod(_r), _typeOp::inv(prod(_l)));\
    \ }\n    _typeT get(int _p) { return _typeOp::op(prod(_p + 1), _typeOp::inv(prod(_p)));\
    \ }\n    _typeT all_query() { return prod(_tree.size()); }\n    void set(int _p,\
    \ const _typeT& _x) { apply(_p, _typeOp::op(_x, _typeOp::inv(get(_p)))); }\n \
    \ };\n}\n#line 4 \"template/alias.hpp\"\n#include <functional>\n#line 7 \"template/alias.hpp\"\
    \n#include <string>\n#include <set>\n#include <map>\n#include <unordered_set>\n\
    #line 16 \"template/alias.hpp\"\n\nnamespace kyopro {\n  using ll = int64_t;\n\
    \  using ull = uint64_t;\n  using lf = double;\n  #ifdef __SIZEOF_INT128__\n \
    \ using i128 = __int128_t;\n  using u128 = __uint128_t;\n  #endif\n  #ifdef __SIZEOF_FLOAT128__\n\
    \  using f128 = __float128;\n  #endif\n\n  template<class T>\n  using vec = std::vector<T>;\n\
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
  - math/all.hpp
  - math/div.hpp
  - math/mod.hpp
  - math/ModInt.hpp
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
  timestamp: '2022-01-11 23:13:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: all.hpp
layout: document
redirect_from:
- /library/all.hpp
- /library/all.hpp.html
title: all.hpp
---

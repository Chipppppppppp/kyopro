---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: kyopro/function/monoid.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\r\n#include <cstddef>\r\n#include <cstdint>\r\n#include <limits>\r\
    \n#include <type_traits>\r\n#include \"kyopro/algorithm/Hash.hpp\"\r\n#include\
    \ \"kyopro/meta/constant.hpp\"\r\n#include \"kyopro/meta/setting.hpp\"\r\n#include\
    \ \"kyopro/meta/trait.hpp\"\r\n#include \"kyopro/io/in.hpp\"\r\n#include \"kyopro/io/out.hpp\"\
    \r\n#include \"Montgomery.hpp\"\r\n\r\nnamespace kpr {\r\n    template<class T,\
    \ std::size_t kind = 0, bool = false>\r\n    struct DynamicModInt {\r\n      \
    \  static_assert(std::is_unsigned_v<T>, \"The given type must be an unsigned integer\
    \ type\");\r\n\r\n        using value_type = T;\r\n\r\n    private:\r\n      \
    \  using larger_type = next_integer_t<T>;\r\n\r\n        inline static Montgomery<T>\
    \ montgomery;\r\n\r\n    public:\r\n        T value;\r\n\r\n        static constexpr\
    \ KYOPRO_BASE_INT get_kind() noexcept {\r\n            return kind;\r\n      \
    \  }\r\n\r\n        static void set_mod(T mod) noexcept {\r\n            montgomery.set_mod(mod);\r\
    \n        }\r\n\r\n        static KYOPRO_BASE_INT get_mod() noexcept {\r\n   \
    \         return montgomery.mod;\r\n        }\r\n\r\n        KYOPRO_BASE_INT get_val()\
    \ noexcept {\r\n            return montgomery.inv_transform(value);\r\n      \
    \  }\r\n\r\n        DynamicModInt() noexcept = default;\r\n        DynamicModInt(T\
    \ value) noexcept: value(montgomery.transform(value % montgomery.mod + montgomery.mod))\
    \ {}\r\n\r\n        template<class U>\r\n        explicit operator U() const noexcept\
    \ {\r\n            return montgomery.inv_transform(value);\r\n        }\r\n\r\n\
    \        static DynamicModInt raw(T value) noexcept {\r\n            DynamicModInt\
    \ res;\r\n            res.value = montgomery.transform(value);\r\n           \
    \ return res;\r\n        }\r\n\r\n        DynamicModInt pow(std::uint_fast64_t\
    \ n) const noexcept {\r\n            DynamicModInt res = 1, a = *this;\r\n   \
    \         while (n > 0) {\r\n                if (n & 1) res = res * a;\r\n   \
    \             a = a * a;\r\n                n >>= 1;\r\n            }\r\n    \
    \        return res;\r\n        }\r\n\r\n        DynamicModInt inv() const noexcept\
    \ {\r\n            return pow(montgomery.mod - 2);\r\n        }\r\n\r\n      \
    \  DynamicModInt operator +() const noexcept {\r\n            return *this;\r\n\
    \        }\r\n\r\n        DynamicModInt operator -() const noexcept {\r\n    \
    \        return value == 0 ? 0 : montgomery.mod - value;\r\n        }\r\n\r\n\
    \        DynamicModInt& operator ++() noexcept {\r\n            *this += DynamicModInt::raw(1);\r\
    \n            return *this;\r\n        }\r\n\r\n        DynamicModInt operator\
    \ ++(int) noexcept {\r\n            DynamicModInt before = *this;\r\n        \
    \    ++*this;\r\n            return before;\r\n        }\r\n\r\n        DynamicModInt&\
    \ operator --() noexcept {\r\n            *this -= DynamicModInt::raw(1);\r\n\
    \            return *this;\r\n        }\r\n\r\n        DynamicModInt operator\
    \ --(int) noexcept {\r\n            DynamicModInt before = *this;\r\n        \
    \    --*this;\r\n            return before;\r\n        }\r\n\r\n        DynamicModInt&\
    \ operator +=(DynamicModInt rhs) noexcept {\r\n            if ((value += rhs.value\
    \ - (montgomery.mod << 1)) > std::numeric_limits<std::make_signed_t<T>>::max())\
    \ value += montgomery.mod << 1;\r\n            return *this;\r\n        }\r\n\r\
    \n        DynamicModInt& operator -=(DynamicModInt rhs) noexcept {\r\n       \
    \     if ((value -= rhs.value) > std::numeric_limits<std::make_signed_t<T>>::max())\
    \ value += montgomery.mod << 1;\r\n            return *this;\r\n        }\r\n\r\
    \n        DynamicModInt& operator *=(DynamicModInt rhs) noexcept {\r\n       \
    \     value = montgomery.reduce(static_cast<larger_type>(value) * rhs.value);\r\
    \n            return *this;\r\n        }\r\n\r\n        DynamicModInt& operator\
    \ /=(DynamicModInt rhs) noexcept {\r\n            value = montgomery.reduce(static_cast<larger_type>(value)\
    \ * rhs.inv().value);\r\n            return *this;\r\n        }\r\n\r\n      \
    \  friend DynamicModInt operator +(DynamicModInt lhs, DynamicModInt rhs) noexcept\
    \ {\r\n            return lhs += rhs;\r\n        }\r\n\r\n        friend DynamicModInt\
    \ operator -(DynamicModInt lhs, DynamicModInt rhs) noexcept {\r\n            return\
    \ lhs -= rhs;\r\n        }\r\n\r\n        friend DynamicModInt operator *(DynamicModInt\
    \ lhs, DynamicModInt rhs) noexcept {\r\n            return lhs *= rhs;\r\n   \
    \     }\r\n\r\n        friend DynamicModInt operator /(DynamicModInt lhs, DynamicModInt\
    \ rhs) noexcept {\r\n            return lhs /= rhs;\r\n        }\r\n\r\n     \
    \   friend bool operator ==(DynamicModInt lhs, DynamicModInt rhs) noexcept {\r\
    \n            return lhs.value == rhs.value;\r\n        }\r\n\r\n        friend\
    \ bool operator !=(DynamicModInt lhs, DynamicModInt rhs) noexcept {\r\n      \
    \      return lhs.value != rhs.value;\r\n        }\r\n\r\n        friend struct\
    \ ScanFunction<DynamicModInt>;\r\n\r\n        friend struct PrintFunction<DynamicModInt>;\r\
    \n    };\r\n\r\n    template<class T, std::size_t kind>\r\n    struct ScanFunction<DynamicModInt<T,\
    \ kind>> {\r\n        template<class Scanner>\r\n        static void scan(Scanner&\
    \ scanner, DynamicModInt<T, kind>& a) {\r\n            std::int_fast64_t value;\r\
    \n            ScanFunction<std::int_fast64_t>::scan(scanner, value);\r\n     \
    \       a.value = a.montgomery.transform(value % a.montgomery.mod + a.montgomery.mod);\r\
    \n        }\r\n    };\r\n\r\n    template<class T, std::size_t kind>\r\n    struct\
    \ PrintFunction<DynamicModInt<T, kind>> {\r\n        template<class Printer>\r\
    \n        static void print(Printer& printer, const DynamicModInt<T, kind>& a)\
    \ {\r\n            PrintFunction<T>::print(printer, a.montgomery.inv_transform(a.value));\r\
    \n        }\r\n    };\r\n\r\n    template<class T, std::size_t kind>\r\n    struct\
    \ Hash<DynamicModInt<T, kind>> {\r\n        using value_type = DynamicModInt<T,\
    \ kind>;\r\n\r\n        std::size_t operator ()(DynamicModInt<T, kind> a) const\
    \ noexcept {\r\n            return static_cast<std::size_t>(a);\r\n        }\r\
    \n    };\r\n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/math/DynamicModInt.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/math/DynamicModInt.hpp
layout: document
redirect_from:
- /library/kyopro/math/DynamicModInt.hpp
- /library/kyopro/math/DynamicModInt.hpp.html
title: kyopro/math/DynamicModInt.hpp
---

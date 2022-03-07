#pragma once
#include <type_traits>
#include "../base/constant.hpp"

namespace kyopro {
  template<class _typeT, _typeT _id = 0>
  struct Plus {
    static_assert(std::is_arithmetic_v<_typeT>);
    static constexpr _typeT id = _id;
    constexpr _typeT operator ()(_typeT _a, _typeT _b) const noexcept { return _a + _b; }
    constexpr _typeT inv(_typeT _a) const noexcept { return -_a; }
  };
  template<class _typeT, _typeT _id = 1>
  struct Mul {
    static_assert(std::is_arithmetic_v<_typeT>);
    static constexpr _typeT id = _id;
    constexpr _typeT operator ()(_typeT _a, _typeT _b) const noexcept { return _a * _b; }
    constexpr _typeT inv(_typeT _a) const noexcept {
      static_assert(!std::is_integral_v<_typeT>);
      return 1 / _a;
    }
  };
  template<class _typeT, _typeT _id = std::is_integral_v<_typeT> ? -INF<_typeT> : -inf>
  struct Max {
    static_assert(std::is_arithmetic_v<_typeT>);
    static constexpr _typeT id = _id;
    constexpr _typeT operator ()(_typeT _a, _typeT _b) const noexcept { return _a > _b ? _a : _b; }
  };
  template<class _typeT, _typeT _id = std::is_integral_v<_typeT> ? INF<_typeT> : inf>
  struct Min {
    static_assert(std::is_arithmetic_v<_typeT>);
    static constexpr _typeT id = _id;
    constexpr _typeT operator ()(_typeT _a, _typeT _b) const noexcept { return _a < _b ? _a : _b; }
  };
}
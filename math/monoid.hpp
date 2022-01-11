#pragma once
#include <type_traits>
#include "../base/constant.hpp"

namespace kyopro {
  template<class _typeT, _typeT _id = 0>
  struct Plus {
    static constexpr _typeT id = _id;
    static constexpr _typeT op(_typeT _a, _typeT _b) noexcept { return _a + _b; }
    static constexpr _typeT inv(_typeT _a) noexcept { return -_a; }
  };
  template<class _typeT, _typeT _id = 1>
  struct Mul {
    static constexpr _typeT id = _id;
    static constexpr _typeT op(_typeT _a, _typeT _b) noexcept { return _a * _b; }
    static constexpr _typeT inv(_typeT _a) noexcept {
      static_assert(!std::is_integral_v<_typeT>);
      return 1 / _a;
    }
  };
  template<class _typeT, _typeT _id = -inf>
  struct Max {
    static constexpr _typeT id = _id;
    static constexpr _typeT op(_typeT _a, _typeT _b) noexcept { return _a > _b ? _a : _b; }
  };
  template<class _typeT, _typeT _id = inf>
  struct Min {
    static constexpr _typeT id = _id;
    static constexpr _typeT op(_typeT _a, _typeT _b) noexcept { return _a < _b ? _a : _b; }
  };
}
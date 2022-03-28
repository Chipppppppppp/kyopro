#pragma once
#include <algorithm>
#include <cstdint>
#include <numeric>
#include <random>
#include <type_traits>
#include "../meta/settings.hpp"
#include "DynamicModInt.hpp"
#include "is_prime.hpp"

namespace kyopro {
  template<class _typeT>
  constexpr _typeT pollard_rho(_typeT _p, KYOPRO_BASE_UINT _c) {
    using _typeU = std::make_unsigned_t<_typeT>;
    using _typeDynamicModInt = DynamicModInt<_typeU, KYOPRO_BASE_UINT(-1)>;
    _typeU _n = _p;
    _typeDynamicModInt::set_mod(_n);
    _typeDynamicModInt _cc = _c;
    auto _f = [=](_typeDynamicModInt _x) noexcept { return _x * _x + _cc; };
    _typeDynamicModInt _x = 1, _y = 2, _z = 1, _q = 1;
    _typeU _g = 1;
    for (int _r = 1; _g == 1; _r <<= 1) {
      _x = _y;
      for (int _i = 0; _i < _r; ++_i) _y = _f(_y);
      for (int _k = 0; _k < _r && _g == 1; _k += 128) {
        _z = _y;
        int _min = std::min(128, _r - _k);
        for (int _i = 0; _i < _min; ++_i) {
          _y = _f(_y);
          _q *= _x - _y;
        }
        _g = std::gcd(static_cast<_typeU>(_q), _n);
      }
    }
    if (_g == _n) {
      do {
        _z = _f(_z);
        _g = std::gcd(static_cast<_typeU>(_x - _z), _n);
      } while (_g == 1);
    }
    return _g;
  }

  KYOPRO_BASE_UINT find_factor(KYOPRO_BASE_UINT _n) noexcept {
    static std::mt19937_64 _mt(std::random_device{}());
    std::uniform_int_distribution<std::uint_fast64_t> _rnd(0, _n - 1);
    if (is_prime(_n)) return _n;
    for (int _i = 0; _i < 100; ++_i) {
      std::uint_fast64_t _m = pollard_rho(_n, _rnd(_mt));
      if (is_prime(_m)) return _m;
      _n = _m;
    }
    return 1;
  }

  template<bool _sorted = true, class _typeContainer = std::vector<KYOPRO_BASE_INT>>
  _typeContainer factorize(KYOPRO_BASE_UINT _n) {
    _typeContainer _res;
    for (int _p = 2; _p < 100 && _p * _p <= _n; ++_p) {
      while (_n % _p == 0) {
        _n /= _p;
        _res.emplace_back(_p);
      }
    }
    while (_n > 1) {
      std::uint_fast64_t _p = find_factor(_n);
      do {
        _n /= _p;
        _res.emplace_back(_p);
      } while (_n % _p == 0);
    }
    if constexpr (_sorted) std::sort(_res.begin(), _res.end());
    return _res;
  }
}
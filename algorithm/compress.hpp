#pragma once
#include <algorithm>
#include <functional>
#include <iterator>
#include <unordered_map>
#include <vector>
#include "../meta/settings.hpp"

namespace kyopro {
  template<class _typeT, class _typeContainer = std::unordered_map<typename std::iterator_traits<_typeT>::value_type, KYOPRO_BASE_INT>, class _typeCompare>
  auto compress(_typeT _first, _typeT _last, _typeCompare _comp = std::less<typename std::iterator_traits<_typeT>::value_type>()) {
    std::vector<typename std::iterator_traits<_typeT>::value_type> _vec(_first, _last);
    std::sort(_vec.begin(), _vec.end(), _comp);
    auto _end = std::unique(_vec.begin(), _vec.end());
    _typeContainer _mem;
    int _cnt = -1;
    for (auto _i = _vec.begin(); _i != _end; ++_i) _mem[*_i] = ++_cnt;
    return _mem;
  }
}
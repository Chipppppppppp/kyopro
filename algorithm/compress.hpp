#pragma once
#include <algorithm>
#include <functional>
#include <iterator>
#include <unordered_map>
#include <vector>
#include "../meta/settings.hpp"

namespace kyopro {
  inline constexpr struct {
    template<class T, class Container = std::unordered_map<typename std::iterator_traits<T>::value_type, KYOPRO_BASE_INT>, class Compare>
    constexpr auto operator ()(T first, T last, Compare comp = std::less<typename std::iterator_traits<T>::value_type>()) const {
      std::vector<typename std::iterator_traits<T>::value_type> vec(first, last);
      std::sort(vec.begin(), vec.end(), comp);
      auto end = std::unique(vec.begin(), vec.end());
      Container mem;
      int cnt = -1;
      for (auto i = vec.begin(); i != end; ++i) mem[*i] = ++cnt;
      return mem;
    }
  } compress;
}
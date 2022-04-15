#pragma once
#include <unistd.h>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include "../math/power.hpp"
#include "../meta/settings.hpp"
#include "../meta/trait.hpp"

namespace kyopro {
  template<KYOPRO_BASE_UINT _buf_size = KYOPRO_BUFFER_SIZE>
  struct Reader {
  private:
    int _fd, _idx;
    std::array<char, _buf_size> _buffer;

  public:
    Reader() {
      read(_fd, _buffer.begin(), _buf_size);
    }
    Reader(int _fd): _fd(_fd), _idx(0), _buffer() {
      read(_fd, _buffer.begin(), _buf_size);
    }
    Reader(FILE* _fp): _fd(fileno(_fp)), _idx(0), _buffer() {
      read(_fd, _buffer.begin(), _buf_size);
    }

    struct iterator {
    private:
      Reader& _reader;

    public:
      using difference_type = void;
      using value_type = void;
      using pointer = void;
      using reference = void;
      using iterator_category = std::input_iterator_tag;

      iterator() noexcept = default;
      iterator(Reader& _reader) noexcept: _reader(_reader) {}

      iterator& operator ++() {
        ++_reader._idx;
        if (_reader._idx == _buf_size) {
          read(_reader._fd, _reader._buffer.begin(), _buf_size);
          _reader._idx = 0;
        }
        return *this;
      }

      iterator operator ++(int) {
        iterator _before = *this;
        operator ++();
        return _before;
      }

      char& operator *() const {
        return _reader._buffer[_reader._idx];
      }
    };

    iterator begin() noexcept {
      return iterator(*this);
    }
  };

  Reader input(0);

  template<class _typeIterator, KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>
  struct Scanner {
  private:
    template<class, class = void>
    struct _has_scan: std::false_type {};
    template<class _typeT>
    struct _has_scan<_typeT, std::void_t<decltype(std::declval<_typeT>().scan(std::declval<Scanner&>()))>>: std::true_type {};

  public:
    static constexpr KYOPRO_BASE_UINT decimal_precision = _decimal_precision;
    _typeIterator itr;

    Scanner() noexcept = default;
    Scanner(_typeIterator _itr) noexcept: itr(_itr) {}

    void discard_space() {
      while (('\t' <= *itr && *itr <= '\r') || *itr == ' ') ++itr;
    }

    void scan(char& _a) {
      discard_space();
      _a = *itr;
      ++itr;
    }
    void scan(std::string& _a) {
      discard_space();
      for (auto& _i: _a) {
        _i = *itr;
        ++itr;
      }
    }
    void scan(bool& _a) {
      discard_space();
      while ('0' <= *itr && *itr <= '9') {
        if (*itr != '0') _a = true;
        ++itr;
      }
    }
    template<class _typeT, std::enable_if_t<std::is_arithmetic_v<_typeT> && !_has_scan<_typeT>::value>* = nullptr>
    void scan(_typeT& _a) {
      discard_space();
      bool _sgn = false;
      if constexpr (!std::is_unsigned_v<_typeT>) if (*itr == '-') {
        _sgn = true;
        ++itr;
      }
      _a = 0;
      for (; '0' <= *itr && *itr <= '9'; ++itr) _a = _a * 10 + *itr - '0';
      if (*itr == '.') {
        ++itr;
        if constexpr (std::is_floating_point_v<_typeT>) {
          constexpr std::uint_fast64_t _power_decimal_precision = power(10ULL, _decimal_precision);
          _typeT _d = 0;
          std::uint_fast64_t _i = 1;
          for (; '0' <= *itr && *itr <= '9' && _i < _power_decimal_precision; _i *= 10) {
            _d = _d * 10 + *itr - '0';
            ++itr;
          }
          _a += _d / _i;
        }
        while ('0' <= *itr && *itr <= '9') ++itr;
      }
      if constexpr (!std::is_unsigned_v<_typeT>) if (_sgn) _a = -_a;
    }
    template<std::size_t _i = 0, class _typeT, std::enable_if_t<is_tuple_v<_typeT> && !_has_scan<_typeT>::value>* = nullptr>
    void scan(_typeT& _a) {
      if constexpr (_i < std::tuple_size_v<_typeT>) {
        scan(std::get<_i>(_a));
        scan<_i + 1>(_a);
      }
    }
    template<class _typeT, std::enable_if_t<is_range_v<_typeT> && !_has_scan<_typeT>::value>* = nullptr>
    void scan(_typeT& _a) {
      for (auto& _i: _a) scan(_i);
    }
    template<class _typeT, std::enable_if_t<_has_scan<_typeT>::value>* = nullptr>
    void scan(_typeT& _a) {
      _a.scan(*this);
    }

    void operator ()() {}
    template<class _typeHead, class... _typeArgs>
    void operator ()(_typeHead& _head, _typeArgs&... _args) {
      scan(_head);
      operator ()(_args...);
    }
  };

  Scanner<Reader<>::iterator> scan(input.begin());
}
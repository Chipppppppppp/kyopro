#pragma once
#include <unistd.h>
#include <array>
#include <cstdint>
#include <cstdio>
#include <iterator>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include "settings.hpp"
#include "trait.hpp"

namespace kyopro {
  template<KYOPRO_BASE_UINT _buf_size = KYOPRO_BUFFER_SIZE>
  struct Writer {
  private:
    int _fd, _idx;
    std::array<char, _buf_size> _buffer;

  public:
    Writer() noexcept = default;
    Writer(int _fd) noexcept: _fd(_fd), _idx(0), _buffer() {}
    Writer(FILE* _fp) noexcept: _fd(fileno_unlocked(_fp)), _idx(0), _buffer() {}

    ~Writer() {
      write(_fd, _buffer.begin(), _idx);
    }

    Writer& operator =(int _fd) noexcept {
      this->_fd = _fd;
      return *this;
    }
    Writer& operator =(FILE* _fp) noexcept {
      this->_fd = fileno_unlocked(_fp);
      return *this;
    }

    struct iterator {
    private:
      Writer& _writer;

    public:
      using difference_type = void;
      using value_type = void;
      using pointer = void;
      using reference = void;
      using iterator_category = std::output_iterator_tag;

      iterator() noexcept = default;
      iterator(Writer& _writer) noexcept: _writer(_writer) {}

      iterator& operator ++() {
        ++_writer._idx;
        if (_writer._idx == _buf_size) {
          write(_writer._fd, _writer._buffer.begin(), _buf_size);
          _writer._idx = 0;
        }
        return *this;
      }

      iterator operator ++(int) {
        iterator _before = *this;
        operator ++();
        return _before;
      }

      char& operator *() const {
        return _writer._buffer[_writer._idx];
      }

      void _flush() const {
        write(_writer._fd, _writer._buffer.begin(), _writer._idx);
      }
    };

    iterator begin() noexcept {
      return iterator(*this);
    }
  };

  Writer output(1), error(2);

  template<class _typeWriter, bool _sep = true, bool _end = true, bool _debug = true, bool _flush = false, KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>
  struct Printer {
  private:
    template<class, class = void>
    struct _has_print: std::false_type {};
    template<class _typeT>
    struct _has_print<_typeT, std::void_t<decltype(_typeT::print)>>: std::true_type {};

    typename _typeWriter::iterator _itr;

    void _print_sep() {
      if constexpr (_debug) {
        _print(',');
      }
      _print(' ');
    }

    void _print(char _a) {
      *_itr = _a;
      ++_itr;
    }
    void _print(const char* _a) {
      for (; *_a; ++_a) _print(*_a);
    }
    void _print(const std::string& _a) {
      for (auto _i: _a) _print(_i);
    }
    void _print(bool _a) {
      _print(static_cast<char>('0' + _a));
    }
    template<class _typeT, std::enable_if_t<std::is_arithmetic_v<_typeT> && !_has_print<_typeT>::value>* = nullptr>
    void _print(_typeT _a) {
      if constexpr (std::is_signed_v<_typeT>) if (_a < 0) {
        _print('-');
        _a = -_a;
      }
      std::uint_fast64_t _p = _a;
      _a -= _p;
      std::string _s;
      do {
        _s += '0' + _p % 10;
        _p /= 10;
      } while (_p > 0);
      for (auto _i = _s.rbegin(); _i != _s.rend(); ++_i) _print(*_i);
      if constexpr (std::is_integral_v<_typeT>) return;
      _print('.');
      for (int _i = 0; _i < static_cast<int>(_decimal_precision); ++_i) {
        _a *= 10;
        _print('0' + static_cast<std::uint_fast64_t>(_a) % 10);
      }
    }
    template<size_t _i = 0, class _typeT, std::enable_if_t<is_tuple_v<_typeT> && !_has_print<_typeT>::value>* = nullptr>
    void _print(const _typeT& _a) {
      if constexpr (_debug && _i == 0) _print('{');
      if constexpr (std::tuple_size_v<_typeT> != 0) _print(std::get<_i>(_a));
      if constexpr (_i + 1 < std::tuple_size_v<_typeT>) {
        if constexpr (_sep) _print_sep();
        _print<_i + 1>(_a);
      } else if constexpr (_debug) _print('}');
    }
    template<class _typeT, std::enable_if_t<is_iterable_v<_typeT> && !_has_print<_typeT>::value>* = nullptr>
    void _print(const _typeT& _a) {
      if constexpr (_debug) _print('{');
      if (std::empty(_a)) return;
      for (auto _i = std::begin(_a); ; ) {
        _print(*_i);
        if (++_i != std::end(_a)) {
          if constexpr (_sep) {
            if constexpr (_debug) {
              _print(',');
              _print(' ');
            } else if constexpr (std::is_arithmetic_v<std::decay_t<decltype(std::declval<_typeT>()[0])>>) _print(' ');
            else _print('\n');
          }
        } else break;
      }
      if constexpr (_debug) _print('}');
    }
    template<class _typeT, std::enable_if_t<_has_print<_typeT>::value>* = nullptr>
    void _print(const _typeT& _a) {
      _a._print();
    }

  public:
    Printer() noexcept = default;
    Printer(_typeWriter& _writer) noexcept: _itr(_writer.begin()) {}

    template<bool = true>
    void operator ()() {
      if constexpr (_end) _print('\n');
      if constexpr (_flush) _itr._flush();
    }
    template<bool _first = true, class _typeHead, class... _typeArgs>
    void operator ()(_typeHead&& _head, _typeArgs&&... _args) {
      if constexpr (_debug && _first) {
        _print('#');
        _print(' ');
      }
      if constexpr (_sep && !_first) _print_sep();
      _print(_head);
      operator ()<false>(std::forward<_typeArgs>(_args)...);
    }
  };

  Printer<Writer<>, false, false, false> print(output), eprint(error);
  Printer<Writer<>, true, true, false> println(output), eprintln(error);
  Printer<Writer<>> debug(output), edebug(error);
}
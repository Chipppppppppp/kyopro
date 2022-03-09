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

      void flush() const {
        write(_writer._fd, _writer._buffer.begin(), _writer._idx);
      }
    };

    iterator begin() noexcept {
      return iterator(*this);
    }
  };

  Writer output(1), error(2);

  template<class _typeIterator, bool _sep = true, bool _end = true, bool _debug = false, bool _comment = false, bool _flush = false, KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>
  struct Printer {
  private:
    template<class, class = void>
    struct _has_print: std::false_type {};
    template<class _typeT>
    struct _has_print<_typeT, std::void_t<decltype(std::declval<_typeT>().print(std::declval<Printer&>()))>>: std::true_type {};

    void _print_sep() {
      if constexpr (_debug) {
        print(',');
      }
      print(' ');
    }

  public:
    static constexpr bool sep = _sep, end = _end, debug = _debug, flush = _flush;
    static constexpr KYOPRO_BASE_UINT decimal_precision = _decimal_precision;

    _typeIterator itr;

    Printer() noexcept = default;
    Printer(_typeIterator _itr) noexcept: itr(_itr) {}

    void print(char _a) {
      *itr = _a;
      ++itr;
    }
    void print(const char* _a) {
      for (; *_a; ++_a) print(*_a);
    }
    void print(const std::string& _a) {
      for (auto _i: _a) print(_i);
    }
    void print(bool _a) {
      print(static_cast<char>('0' + _a));
    }
    template<class _typeT, std::enable_if_t<std::is_arithmetic_v<_typeT> && !_has_print<_typeT>::value>* = nullptr>
    void print(_typeT _a) {
      if constexpr (std::is_signed_v<_typeT>) if (_a < 0) {
        print('-');
        _a = -_a;
      }
      std::uint_fast64_t _p = _a;
      _a -= _p;
      std::string _s;
      do {
        _s += '0' + _p % 10;
        _p /= 10;
      } while (_p > 0);
      for (auto _i = _s.rbegin(); _i != _s.rend(); ++_i) print(*_i);
      if constexpr (std::is_integral_v<_typeT>) return;
      print('.');
      for (int _i = 0; _i < static_cast<int>(_decimal_precision); ++_i) {
        _a *= 10;
        print('0' + static_cast<std::uint_fast64_t>(_a) % 10);
      }
    }
    template<size_t _i = 0, class _typeT, std::enable_if_t<is_tuple_v<_typeT> && !_has_print<_typeT>::value>* = nullptr>
    void print(const _typeT& _a) {
      if constexpr (_debug && _i == 0) print('{');
      if constexpr (std::tuple_size_v<_typeT> != 0) print(std::get<_i>(_a));
      if constexpr (_i + 1 < std::tuple_size_v<_typeT>) {
        if constexpr (_sep) _print_sep();
        print<_i + 1>(_a);
      } else if constexpr (_debug) print('}');
    }
    template<class _typeT, std::enable_if_t<is_iterable_v<_typeT> && !_has_print<_typeT>::value>* = nullptr>
    void print(const _typeT& _a) {
      if constexpr (_debug) print('{');
      if (std::empty(_a)) return;
      for (auto _i = std::begin(_a); ; ) {
        print(*_i);
        if (++_i != std::end(_a)) {
          if constexpr (_sep) {
            if constexpr (_debug) {
              print(',');
              print(' ');
            } else if constexpr (std::is_arithmetic_v<std::decay_t<decltype(std::declval<_typeT>()[0])>>) print(' ');
            else print('\n');
          }
        } else break;
      }
      if constexpr (_debug) print('}');
    }
    template<class _typeT, std::enable_if_t<_has_print<_typeT>::value>* = nullptr>
    void print(const _typeT& _a) {
      _a.print(*this);
    }

    template<bool = true>
    void operator ()() {
      if constexpr (_end) print('\n');
      if constexpr (_flush) itr._flush();
    }
    template<bool _first = true, class _typeHead, class... _typeArgs>
    void operator ()(_typeHead&& _head, _typeArgs&&... _args) {
      if constexpr (_comment && _first) {
        print('#');
        print(' ');
      }
      if constexpr (_sep && !_first) _print_sep();
      print(_head);
      operator ()<false>(std::forward<_typeArgs>(_args)...);
    }
  };

  Printer<Writer<>::iterator, false, false> print(output.begin()), eprint(error.begin());
  Printer<Writer<>::iterator> println(output.begin()), eprintln(error.begin());
  Printer<Writer<>::iterator, true, true, true, true> debug(output.begin()), edebug(error.begin());
}
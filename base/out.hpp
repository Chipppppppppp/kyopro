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
  template<KYOPRO_BASE_UINT buf_size = KYOPRO_BUFFER_SIZE>
  struct Writer {
  private:
    int fd, idx;
    std::array<char, buf_size> buffer;

  public:
    Writer() noexcept = default;
    Writer(int fd) noexcept: fd(fd), idx(0), buffer() {}
    Writer(FILE* fp) noexcept: fd(fileno_unlocked(fp)), idx(0), buffer() {}

    ~Writer() {
      write(fd, buffer.begin(), idx);
    }

    Writer& operator =(int fd) noexcept {
      this->fd = fd;
      return *this;
    }
    Writer& operator =(FILE* fp) noexcept {
      this->fd = fileno_unlocked(fp);
      return *this;
    }

    struct iterator {
    private:
      Writer& writer;

    public:
      using difference_type = void;
      using value_type = void;
      using pointer = void;
      using reference = void;
      using iterator_category = std::output_iterator_tag;

      iterator() noexcept = default;
      iterator(Writer& writer) noexcept: writer(writer) {}

      iterator& operator ++() {
        ++writer.idx;
        if (writer.idx == buf_size) {
          write(writer.fd, writer.buffer.begin(), buf_size);
          writer.idx = 0;
        }
        return *this;
      }

      iterator operator ++(int) {
        iterator before = *this;
        operator ++();
        return before;
      }

      char& operator *() const {
        return writer.buffer[writer.idx];
      }

      void flush() const {
        write(writer.fd, writer.buffer.begin(), writer.idx);
      }
    };

    iterator begin() noexcept {
      return iterator(*this);
    }
  };

  Writer output(1), error(2);

  template<class Writer, bool sep = true, bool end = true, bool debug = true, bool flush = false, KYOPRO_BASE_UINT decimal_precision = KYOPRO_DECIMAL_PRECISION>
  struct Printer {
  private:
    template<class, class = void>
    struct has_print: std::false_type {};
    template<class T>
    struct has_print<T, std::void_t<decltype(T::print)>>: std::true_type {};

    typename Writer::iterator itr;

    void print_sep() {
      if constexpr (debug) {
        print(',');
      }
      print(' ');
    }

    void print(char a) {
      *itr = a;
      ++itr;
    }
    void print(const char* a) {
      for (; *a; ++a) print(*a);
    }
    void print(const std::string& a) {
      for (auto i: a) print(i);
    }
    void print(bool a) {
      print('0' + a);
    }
    template<class T, std::enable_if_t<std::is_arithmetic_v<T> && !has_print<T>::value>* = nullptr>
    void print(T a) {
      if constexpr (std::is_signed_v<T>) if (a < 0) {
        print('-');
        a = -a;
      }
      std::uint_fast64_t p = a;
      a -= p;
      std::string s;
      do {
        s += '0' + p % 10;
        p /= 10;
      } while (p > 0);
      for (auto i = s.rbegin(); i != s.rend(); ++i) print(*i);
      if constexpr (std::is_integral_v<T>) return;
      print('.');
      for (int i = 0; i < static_cast<int>(decimal_precision); ++i) {
        a *= 10;
        print('0' + static_cast<std::uint_fast64_t>(a) % 10);
      }
    }
    template<size_t i = 0, class T, std::enable_if_t<is_tuple_v<T> && !has_print<T>::value>* = nullptr>
    void print(const T& a) {
      if constexpr (debug && i == 0) print('{');
      if constexpr (std::tuple_size_v<T> != 0) print(std::get<i>(a));
      if constexpr (i + 1 < std::tuple_size_v<T>) {
        if constexpr (sep) print_sep();
        print<i + 1>(a);
      } else if constexpr (debug) print('}');
    }
    template<class T, std::enable_if_t<is_iterable_v<T> && !has_print<T>::value>* = nullptr>
    void print(const T& a) {
      if constexpr (debug) print('{');
      if (std::empty(a)) return;
      for (auto i = std::begin(a); ; ) {
        print(*i);
        if (++i != std::end(a)) {
          if constexpr (sep) {
            if constexpr (debug) {
              print(',');
              print(' ');
            } else if constexpr (std::is_arithmetic_v<std::decay_t<decltype(std::declval<T>()[0])>>) print(' ');
            else print('\n');
          }
        } else break;
      }
      if constexpr (debug) print('}');
    }
    template<class T, std::enable_if_t<has_print<T>::value>* = nullptr>
    void print(const T& a) {
      a.print();
    }

  public:
    Printer() noexcept = default;
    Printer(Writer& writer) noexcept: itr(writer.begin()) {}

    template<bool first = true>
    void operator ()() {
      if constexpr (sep && !first) print_sep();
      if constexpr (end) print('\n');
      if constexpr (flush) itr.flush();
    }
    template<bool first = true, class Head, class... Args>
    void operator ()(Head&& head, Args&&... args) {
      if constexpr (debug && first) {
        print('#');
        print(' ');
      }
      if constexpr (sep && !first) print_sep();
      print(head);
      operator ()<false>(std::forward<Args>(args)...);
    }
  };

  Printer<Writer<>, false, false, false> print(output), eprint(error);
  Printer<Writer<>, true, true, false> println(output), eprintln(error);
  Printer<Writer<>> debug(output), edebug(error);
}
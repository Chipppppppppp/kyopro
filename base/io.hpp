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
  template<KYOPRO_BASE_UINT buf_size = KYOPRO_BUFFER_SIZE, KYOPRO_BASE_UINT decimal_precision = KYOPRO_DECIMAL_PRECISION>
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
      int fd;
      int& idx;
      std::array<char, buf_size>& buffer;
    public:
      iterator() noexcept = default;
      iterator(int fd, int& idx, std::array<char, buf_size>& buffer) noexcept: fd(fd), idx(idx), buffer(buffer) {}
      using difference_type = void;
      using value_type = void;
      using pointer = void;
      using reference = void;
      using iterator_category = std::output_iterator_tag;
      iterator& operator ++() {
        ++idx;
        if (idx == buf_size) {
          write(fd, buffer.begin(), buf_size);
          idx = 0;
        }
        return *this;
      }
      iterator operator ++(int) noexcept {
        iterator before = *this;
        operator ++();
        return before;
      }
      char& operator *() const {
        return buffer[idx];
      }
      void flush() {
        write(fd, buffer.begin(), idx);
      }
    };

    iterator begin() const noexcept {
      return iterator(fd, idx, buffer);
    }
  };

  Writer output(1), error(2);

  template<class Writer, bool sep = true, bool end = true, bool debug = true, bool flush = false>
  struct Printer {
  private:
    template<class, class = void>
    struct has_print: std::false_type {};
    template<class T>
    struct has_print<T, std::void_t<decltype(T::print)>>: std::true_type {};
    typename Writer::iterator itr;

    void print_sep() {
      if constexpr (debug) {
        operator ()(',');
      }
      operator ()(' ');
    }

    void print(char a) {
      *itr = a;
      ++itr;
    }
    void print(const char* a) {
      for (; *a; ++a) operator ()(*a);
    }
    void print(const str& a) {
      for (auto i: a) operator ()(i);
    }
    void print(bool a) {
      operator ()('0' + a);
    }
    template<class T, std::enable_if_t<std::is_arithmetic_v<T> && !has_print<T>::value>* = nullptr>
    void print(T a) {
      if constexpr (std::is_signed_v<T>) if (a < 0) {
        operator ()('-');
        a = -a;
      }
      std::uint_fast64_t p = a;
      a -= p;
      std::string s;
      do {
        s += '0' + p % 10;
        p /= 10;
      } while (p > 0);
      for (auto i = s.rbegin(); i != s.rend(); ++i) operator ()(*i);
      if constexpr (std::is_integral_v<T>) return;
      operator ()('.');
      for (int i = 0; i < static_cast<int>(decimal_precision); ++i) {
        a *= 10;
        operator ()('0' + static_cast<std::uint_fast64_t>(a) % 10);
      }
    }
    static void print(tuple<>) noexcept {}
    template<size_t i = 0, class T, std::enable_if_t<is_tuple_v<T> && !has_print<T>::value>* = nullptr>
    void print(const T& a) {
      if constexpr (debug) operator ()('{');
      operator ()(std::get<i>(a));
      if constexpr (i + 1 < std::tuple_size_v<T>) {
        if constexpr (sep) print_sep();
        operator ()<i + 1>(a);
      }
      if constexpr (debug) operator ()('}');
    }
    template<class T, std::enable_if_t<is_iterable_v<T> && !has_print<T>::value>* = nullptr>
    void print(const T& a) {
      if constexpr (debug) operator ()('{');
      if (std::empty(a)) return;
      for (auto i = std::begin(a); ; ) {
        operator ()(*i);
        if (++i != std::end(a)) {
          if constexpr (sep) {
            if constexpr (debug) {
              operator ()(',');
              operator ()(' ');
            } else if constexpr (std::is_arithmetic_v<std::decay_t<decltype(std::declval<T>()[0])>>) operator ()(' ');
            else operator ()('\n');
          }
        } else break;
      }
      if constexpr (debug) operator ()('}');
    }
    template<class T, std::enable_if_t<has_print<T>::value>* = nullptr>
    void print(const T& a) {
      a.print();
    }

  public:
    Printer() noexcept = default;
    Printer(const Writer& writer) noexcept: itr(writer.begin()) {}

    void operator ()() {
      if constexpr (end) operator ()('\n');
      if constexpr (flush) itr.flush();
    }
    template<class Head>
    void operator ()(Head&& head) {
      print(head);
      operator ()();
    }
    template<class Head, class... Args>
    void operator ()(Head&& head, Args&&... args) {
      print(head);
      if constexpr (sep) print_sep();
      operator ()(std::forward<Args>(args)...);
    }
  };

  Printer<Writer<>, false, false, false> print(output), eprint(error);
  Printer<Writer<>, true, true, false> println(output), eprintln(error);
  Printer<Writer<>> debug(output), edebug(error);
}
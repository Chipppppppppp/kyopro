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
  template<std::size_t _buf_size = KYOPRO_BUFFER_SIZE>
  struct Reader {
    static constexpr KYOPRO_BASE_UINT buf_size = _buf_size;

  private:
    int fd, idx;
    std::array<char, buf_size> buffer;

  public:
    Reader() {
      read(fd, buffer.begin(), buf_size);
    }
    Reader(int fd): fd(fd), idx(0), buffer() {
      read(fd, buffer.begin(), buf_size);
    }
    Reader(FILE* fp): fd(fileno(fp)), idx(0), buffer() {
      read(fd, buffer.begin(), buf_size);
    }

    struct iterator {
    private:
      Reader& reader;

    public:
      using difference_type = void;
      using value_type = void;
      using pointer = void;
      using reference = void;
      using iterator_category = std::input_iterator_tag;

      iterator() noexcept = default;
      iterator(Reader& reader) noexcept: reader(reader) {}

      iterator& operator ++() {
        ++reader.idx;
        if (reader.idx == buf_size) {
          read(reader.fd, reader.buffer.begin(), buf_size);
          reader.idx = 0;
        }
        return *this;
      }

      iterator operator ++(int) {
        iterator before = *this;
        operator ++();
        return before;
      }

      char& operator *() const {
        return reader.buffer[reader.idx];
      }
    };

    iterator begin() noexcept {
      return iterator(*this);
    }
  };

  Reader input(0);

  template<class Iterator, std::size_t _decimal_precision = KYOPRO_DECIMAL_PRECISION>
  struct Scanner {
    using iterator_type = Iterator;
    static constexpr KYOPRO_BASE_UINT decimal_precision = _decimal_precision;

  private:
    template<class, class = void>
    struct has_scan: std::false_type {};
    template<class T>
    struct has_scan<T, std::void_t<decltype(std::declval<T>().scan(std::declval<Scanner&>()))>>: std::true_type {};

  public:
    Iterator itr;

    Scanner() noexcept = default;
    Scanner(Iterator itr) noexcept: itr(itr) {}

    void discard_space() {
      while (('\t' <= *itr && *itr <= '\r') || *itr == ' ') ++itr;
    }

    void scan(char& a) {
      discard_space();
      a = *itr;
      ++itr;
    }
    void scan(std::string& a) {
      discard_space();
      while ((*itr < '\t' || '\r' < *itr) && *itr != ' ') {
        a += *itr;
        ++itr;
      }
    }
    void scan(bool& a) {
      discard_space();
      while ('0' <= *itr && *itr <= '9') {
        if (*itr != '0') a = true;
        ++itr;
      }
    }
    template<class T, std::enable_if_t<std::is_arithmetic_v<T> && !has_scan<T>::value>* = nullptr>
    void scan(T& a) {
      discard_space();
      bool sgn = false;
      if constexpr (!std::is_unsigned_v<T>) if (*itr == '-') {
        sgn = true;
        ++itr;
      }
      a = 0;
      for (; '0' <= *itr && *itr <= '9'; ++itr) a = a * 10 + *itr - '0';
      if (*itr == '.') {
        ++itr;
        if constexpr (std::is_floating_point_v<T>) {
          constexpr std::uint_fast64_t power_decimal_precision = power(10ULL, decimal_precision);
          T d = 0;
          std::uint_fast64_t i = 1;
          for (; '0' <= *itr && *itr <= '9' && i < power_decimal_precision; i *= 10) {
            d = d * 10 + *itr - '0';
            ++itr;
          }
          a += d / i;
        }
        while ('0' <= *itr && *itr <= '9') ++itr;
      }
      if constexpr (!std::is_unsigned_v<T>) if (sgn) a = -a;
    }
    template<KYOPRO_BASE_UINT i = 0, class T, std::enable_if_t<is_agg_v<T> && !has_scan<T>::value>* = nullptr>
    void scan(T& a) {
      if constexpr (i < std::tuple_size_v<T>) {
        scan(std::get<i>(a));
        scan<i + 1>(a);
      }
    }
    template<class T, std::enable_if_t<is_iterable_v<T> && !has_scan<T>::value>* = nullptr>
    void scan(T& a) {
      for (auto&& i: a) scan(i);
    }
    template<class T, std::enable_if_t<has_scan<T>::value>* = nullptr>
    void scan(T& a) {
      a.scan(*this);
    }

    void operator ()() {}
    template<class Head, class... Args>
    void operator ()(Head& head, Args&... args) {
      scan(head);
      operator ()(args...);
    }
  };

  Scanner<Reader<>::iterator> scan(input.begin());
}
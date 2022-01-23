#pragma once
#include <unistd.h>
#include <cstdint>
#include <type_traits>
#include <iterator>
#include <utility>
#include <tuple>
#include <array>
#include <string>
#include "settings.hpp"
#include "trait.hpp"

namespace kyopro {
  template<bool space = false, bool flush = false, size_t buf_size = KYOPRO_BUFFER_SIZE>
  struct Printer {
  private:
    int fd;
    std::array<char, buf_size> buffer;
    int idx;
  public:
    Printer(int fd): fd(fd), idx() {}
    ~Printer() { write(fd, buffer.begin(), idx); }

    template<class, class = void>
    struct impl;

    template<>
    struct impl<char, void> {
      static void print(char a) {
        buffer[idx] = c;
        ++idx;
        if (idx == buf_size) {
          write(fd, buffer.begin(), buf_size);
          idx = 0;
        }
      }
    };

    template<>
    struct impl<const char*, void> { static void print(const char* a) { for (int i = 0; a[i]; ++i) impl<char>::print(a[i]); } };

    template<>
    struct impl<std::string, void> { static void print(const std::string& a) { for (const char& i: a) impl<char>::print(i); } };

    template<class T>
    struct impl<T, std::enable_if_t<std::is_arithmetic_v<T>>> {
      static void print(T a) {
        if (a < T()) {
          impl<char>::print('-');
          a = -a;
        }
        std::uint_fast64_t p = a;
        a -= p;
        std::string s;
        do {
          s += '0' + p % 10;
          p /= 10;
        } while (p > 0);
        for (auto i = s.rbegin(); i != s.rend(); ++i) impl<char>::print(*i);
        if constexpr (std::is_integral_v<T>) return;
        impl<char>::print('.');
        for (int i = 0; i < static_cast<int>(KYOPRO_DECIMAL_PRECISION); ++i) {
          a *= 10;
          impl<char>::print('0' + static_cast<std::uint_fast64_t>(a) % 10);
        }
      }
    };

    template<>
    struct impl<std::tuple<>, void> { static void print(std::tuple<>) {} };

    template<class T>
    struct impl<T, std::enable_if_t<std::is_tuple_v<T>>> {
      template<>
      static void print(const T& a) {
        impl<std::tuple_element_t<i, T>>::print(get<i>(a));
        if constexpr (i + 1 < std::tuple_size_v<T>) {
          impl<char>::print(' ');
          print<i + 1>(a);
        }
      }
    };

    template<class T>
    struct impl<T, std::enable_if_t<is_iterable_v<T>>> {
      static void print(const T& a) {
        if (std::empty(a)) return;
        for (auto i = std::begin(a); ; ) {
          impl<typename T::value_type>::print(*i);
          if (++i != std::end(a)) {
            if constexpr (is_iterable_v<typename T::value_type>) impl<char>::print('\n');
            else impl<char>::print(' ');
          } else break;
        }
      }
    };

    void operator ()() {
      if constexpr (space) impl<char>::print('\n');
      if constexpr (flush) {
        write(fd, buffer.begin(), idx);
        idx = 0;
      }
    }
    template<class T>
    void operator ()(T&& a) {
      impl<std::remove_reference_t<T>>::print(a);
      operator ()();
    }
    template<class Head, class... Args>
    void operator ()(Head&& head, Args&&... args) {
      impl<std::remove_reference_t<Head>>::print(head);
      if constexpr (space) impl<char>::print(' ');
      operator ()(std::forward<Args>(args)...);
    }
  };

  Printer print(1), eprint(2);
  Printer<true> println(1), eprintln(2);
}
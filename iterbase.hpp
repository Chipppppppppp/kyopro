#include <iterator>
#include <cstddef>

namespace itertools {
  namespace iterbase {
    // Derived: 継承するクラス, IteratorCategory: イテレータの分類, ValueType: 参照先の型
    template<class Derived, class IteratorCategory, class ValueType>
    struct IteratorBase;

    // Forward Iterator Base
    template<class Derived, class ValueType>
    struct IteratorBase<Derived, ValueType, std::forward_iterator_tag> {
      // イテレータの情報
      using value_type = ValueType;
      using pointer = ValueType*;
      using reference = ValueType&;
      using difference_type = std::ptrdiff_t;
      using iterator_category = std::forward_iterator_tag;

      // 仮想関数(子クラスで定義する)
      virtual constexpr ValueType operator *() const noexcept;
      virtual constexpr Derived& operator ++() noexcept;
      virtual constexpr bool operator ==(const Derived&) const noexcept;

      // ここからは定義しなくてよい
      constexpr Derived operator ++(int) noexcept {
        Derived before = *this;
        ++(*this);
        return before;
      }
      constexpr ValueType operator !=(const Derived& rhs) const noexcept {
        return !*this == rhs;
      }
    };

    // Bidirectional Iterator Base
    template<class Derived, class ValueType>
    struct IteratorBase<Derived, ValueType, std::bidirectional_iterator_tag>: IteratorBase<Derived, ValueType, std::forward_iterator_tag> {
      // イテレータの情報
      using value_type = ValueType;
      using pointer = ValueType*;
      using reference = ValueType&;
      using difference_type = std::ptrdiff_t;
      using iterator_category = std::bidirectional_iterator_tag;

      // 仮想関数(子クラスで定義する)
      virtual constexpr Derived& operator --() noexcept;

      // ここからは定義しなくてよい
      constexpr Derived operator --(int) noexcept {
        Derived before = *this;
        --(*this);
        return before;
      }
    };

    // Random Access Iterator Base
    template<class Derived, class ValueType>
    struct IteratorBase<Derived, ValueType, std::random_access_iterator_tag>: IteratorBase<Derived, ValueType, std::bidirectional_iterator_tag> {
      // イテレータの情報
      using value_type = ValueType;
      using pointer = ValueType*;
      using reference = ValueType&;
      using difference_type = std::ptrdiff_t;
      using iterator_category = std::random_access_iterator_tag;

      // 仮想関数(子クラスで定義する)
      virtual constexpr Derived operator +(std::ptrdiff_t rhs) const noexcept;
      virtual constexpr std::ptrdiff_t operator -(const Derived&) const noexcept;
    private:
      virtual constexpr int compare(const Derived&) const noexcept;
    public:

      // ここからは定義しなくてよい
      constexpr Derived& operator +=(std::ptrdiff_t rhs) noexcept {
        return *this = *this + rhs;
      }
      constexpr Derived operator -(std::ptrdiff_t rhs) const noexcept {
        return *this + -rhs;
      }
      constexpr Derived& operator -=(std::ptrdiff_t rhs) noexcept {
        return *this = *this - rhs;
      }
      virtual constexpr bool operator ==(const Derived& rhs) const noexcept {
        return compare(rhs) == 0;
      }
      virtual constexpr bool operator !=(const Derived& rhs) const noexcept {
        return compare(rhs) != 0;
      }
      virtual constexpr bool operator <(const Derived& rhs) const noexcept {
        return compare(rhs) < 0;
      }
      virtual constexpr bool operator <=(const Derived& rhs) const noexcept {
        return compare(rhs) <= 0;
      }
      virtual constexpr bool operator >(const Derived& rhs) const noexcept {
        return compare(rhs) > 0;
      }
      virtual constexpr bool operator >=(const Derived& rhs) const noexcept {
        return compare(rhs) >= 0;
      }
    };
  }
}

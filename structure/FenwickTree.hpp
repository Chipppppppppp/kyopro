#pragma once
#include <type_traits>
#include <utility>
#include <vector>
#include "../function/monoid.hpp"
#include "../meta/settings.hpp"

namespace kyopro {
  template<class _typeT, class _typeOp = Plus<_typeT>, class _typeContainer = std::vector<_typeT>>
  struct FenwickTree {
  private:
    [[no_unique_address]] _typeOp _op;
    _typeContainer _tree;

  public:
    using value_type = _typeT;
    using size_type = KYOPRO_BASE_UINT;
    using reference = _typeT&;
    using const_reference = const _typeT&;

    FenwickTree() noexcept = default;
    FenwickTree(KYOPRO_BASE_UINT _n) noexcept: _tree(_n, _op.id) {}
    template<class _typeC, std::enable_if_t<std::is_same_v<_typeContainer, std::decay_t<_typeC>>>>
    FenwickTree(_typeC&& _tree): _tree(std::forward<_typeC>(_tree)) {}

    KYOPRO_BASE_UINT size() noexcept { return _tree.size(); }

    void apply(int _p, const _typeT& _x) {
      ++_p;
      while (_p <= (int)size()) {
        _tree[_p - 1] = _op(_tree[_p - 1], _x);
        _p += _p & -_p;
      }
    }

    _typeT prod(int _r) const {
      _typeT _s = _op.id;
      while (_r > 0) {
        _s = _op(_s, _tree[_r - 1]);
        _r -= _r & -_r;
      }
      return _s;
    }
    _typeT prod(int _l, int _r) const { return _op(prod(_r), _op.inv(prod(_l))); }

    _typeT all_prod() { return prod(_tree.size()); }

    _typeT get(int _p) { return _op(prod(_p + 1), _op.inv(prod(_p))); }

    void set(int _p, const _typeT& _x) { apply(_p, _op(_x, _op.inv(get(_p)))); }
  };
}

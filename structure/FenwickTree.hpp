#pragma once
/* FenwickTree */
#include <vector>
#include <utility>
#include "../base/settings.hpp"
#include "../math/monoid.hpp"

namespace kyopro {
  template<class _typeT, class _typeOp = Plus<_typeT>, class _typeContainer = std::vector<_typeT>>
  struct FenwickTree {
  private:
    _typeContainer _tree;
  public:
    using value_type = _typeT;
    using size_type = KYOPRO_BASE_UINT;
    using reference = _typeT&;
    using const_reference = const _typeT&;
    FenwickTree() noexcept = default;
    FenwickTree(KYOPRO_BASE_UINT _n) noexcept: _tree(_n, _typeOp::id) {}
    KYOPRO_BASE_UINT size() noexcept { return _tree.size(); }
    void apply(int _p, const _typeT& _x) {
      ++_p;
      while (_p <= (int)size()) {
        _tree[_p - 1] = _typeOp::op(_tree[_p - 1], _x);
        _p += _p & -_p;
      }
    }
    _typeT prod(int _r) const {
      _typeT _s = _typeOp::id;
      while (_r > 0) {
        _s = _typeOp::op(_s, _tree[_r - 1]);
        _r -= _r & -_r;
      }
      return _s;
    }
    _typeT prod(int _l, int _r) const { return _typeOp::op(prod(_r), _typeOp::inv(prod(_l))); }
    _typeT get(int _p) { return _typeOp::op(prod(_p + 1), _typeOp::inv(prod(_p))); }
    _typeT all_query() { return prod(_tree.size()); }
    void set(int _p, const _typeT& _x) { apply(_p, _typeOp::op(_x, _typeOp::inv(get(_p)))); }
  };
}

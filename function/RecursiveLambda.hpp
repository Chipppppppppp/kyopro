#pragma once
#include <type_traits>
#include <utility>

namespace kyopro {
  template<class _typeF>
  struct RecursiveLambda {
  private:
    _typeF _func;

  public:
    template<class _typeG>
    constexpr RecursiveLambda(_typeG&& _func) noexcept: _func(std::forward<_typeG>(_func)) {}
    template<class... _typeArgs>
    constexpr decltype(auto) operator ()(_typeArgs&&... _args) const noexcept { return _func(*this, std::forward<_typeArgs>(_args)...); }
  };

  template<class _typeF>
  RecursiveLambda(_typeF&&) -> RecursiveLambda<std::decay_t<_typeF>>;
}
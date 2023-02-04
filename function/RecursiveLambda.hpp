#pragma once
#include <type_traits>
#include <utility>

namespace kpr {
    // 再帰可能関数クラス
    template<class F>
    struct RecursiveLambda {
        using value_type = F;

    private:
        F func;

    public:
        template<class G>
        constexpr RecursiveLambda(G&& func) noexcept: func(std::forward<G>(func)) {}

        template<class... Args>
        constexpr decltype(auto) operator ()(Args&&... args) const noexcept(noexcept(func(*this, std::forward<Args>(args)...))) {
            return func(*this, std::forward<Args>(args)...);
        }
    };

    template<class F>
    RecursiveLambda(F&&) -> RecursiveLambda<std::decay_t<F>>;
} // namespace kpr

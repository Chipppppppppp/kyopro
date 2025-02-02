#pragma once
#include <algorithm>
#include <cstdint>
#include <utility>
#include <vector>
#include "../algorithm/bit.hpp"
#include "../function/monoid.hpp"
#include "../meta/setting.hpp"

namespace kpr
{
    template <class T, class Op = Add<T>>
    struct SegmentTree
    {
        using value_type = T;
        using num_type = std::size_t;
        using reference = T &;
        using const_reference = const T &;
        using operator_type = Op;

    private:
        int n, log, num;
        std::vector<T> tree;
        Op op;

        void update(int k)
        {
            tree[k] = op(tree[2 * k], tree[2 * k + 1]);
        }

    public:
        SegmentTree() noexcept = default;
        template <class... Args>
        explicit SegmentTree(Args &&...args)
        {
            std::vector<T> v(std::forward<Args>(args)...);
            n = v.size();
            log = ceil_bit(n);
            num = 1 << log;
            tree = std::vector<T>(num * 2, op.id());
            std::move(v.begin(), v.end(), tree.begin() + num);
            for (int i = num - 1; i >= 1; --i)
                update(i);
        }

        std::size_t size() const noexcept
        {
            return n;
        }

        void set(int p, const T &x)
        {
            p += num;
            tree[p] = x;
            for (int i = 1; i <= log; ++i)
                update(p >> i);
        }

        T get(int p) const
        {
            return tree[p + num];
        }

        T prod(int r) const
        {
            T sl = op.id(), sr = op.id();
            int l = num;
            r += num;
            while (l < r)
            {
                if (l & 1)
                {
                    sl = op(std::move(sl), tree[l]);
                    ++l;
                }
                if (r & 1)
                {
                    --r;
                    sr = op(tree[r], std::move(sr));
                }
                l >>= 1;
                r >>= 1;
            }
            return op(sl, sr);
        }
        T prod(int l, int r) const
        {
            T sl = op.id(), sr = op.id();
            l += num;
            r += num;
            while (l < r)
            {
                if (l & 1)
                {
                    sl = op(std::move(sl), tree[l]);
                    ++l;
                }
                if (r & 1)
                {
                    --r;
                    sr = op(tree[r], std::move(sr));
                }
                l >>= 1;
                r >>= 1;
            }
            return op(sl, sr);
        }

        T all_prod() const
        {
            return tree[1];
        }

        template <class F>
        KYOPRO_BASE_INT max_right(int l, F &&func) const
        {
            if (l == n)
                return n;
            l += num;
            T s = op.id();
            do
            {
                while (!(l & 1))
                    l >>= 1;
                if (!func(op(s, tree[l])))
                {
                    while (l < num)
                    {
                        l *= 2;
                        if (func(op(s, tree[l])))
                        {
                            s = op(std::move(s), tree[l]);
                            ++l;
                        }
                    }
                    return l - num;
                }
                s = op(std::move(s), tree[l]);
                ++l;
            } while ((l & -l) != l);
            return n;
        }

        template <class F>
        KYOPRO_BASE_INT min_left(int r, F &&func) const
        {
            if (r == 0)
                return 0;
            r += num;
            T s = op.id();
            do
            {
                --r;
                while (r > 1 && (r & 1))
                    r >>= 1;
                if (!func(op(tree[r], s)))
                {
                    while (r < num)
                    {
                        r = r * 2 + 1;
                        if (func(op(tree[r], s)))
                        {
                            s = op(tree[r], std::move(s));
                            --r;
                        }
                    }
                    return r + 1 - num;
                }
                s = op(tree[r], std::move(s));
            } while ((r & -r) != r);
            return 0;
        }
    };
} // namespace kpr

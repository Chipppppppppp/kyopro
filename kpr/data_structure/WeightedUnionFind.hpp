#pragma once
#include <algorithm>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>
#include "../function/monoid.hpp"
#include "../meta/setting.hpp"
#include "../meta/trait.hpp"

namespace kpr
{
    template <class T, class Op = Add<T>>
    struct WeightedUnionFind
    {
    private:
        std::vector<int> par;
        std::vector<T> diff_weight;
        Op op;

    public:
        WeightedUnionFind() noexcept = default;
        WeightedUnionFind(std::size_t n) noexcept : par(n, -1), diff_weight(n, op.id()) {}

        void resize(std::size_t n)
        {
            par.resize(n, -1);
            diff_weight.resize(n, op.id());
        }
        void assign(std::size_t n)
        {
            par.assign(n, -1);
            diff_weight.assign(n, op.id());
        }
        void clear()
        {
            std::fill(par.begin(), par.end(), -1);
            std::fill(diff_weight.begin(), diff_weight.end(), op.id());
        }

        std::size_t size() const noexcept
        {
            return par.size();
        }

        KYOPRO_BASE_INT find(int x)
        {
            if (par[x] < 0)
                return x;
            int r = find(par[x]);
            diff_weight[x] = op(std::move(diff_weight[x]), diff_weight[par[x]]);
            return par[x] = r;
        }

        T weight(int x)
        {
            return find(x), diff_weight[x];
        }

        T diff(int x, int y)
        {
            return op(weight(y), op.inv(weight(x)));
        }

        bool merge(int x, int y, T w)
        {
            w = op(std::move(w), op(weight(x), op.inv(weight(y))));
            x = find(x), y = find(y);
            if (x == y)
                return false;
            if (par[x] > par[y])
            {
                par[y] += par[x];
                par[x] = y;
                diff_weight[x] = op.inv(w);
            }
            else
            {
                par[x] += par[y];
                par[y] = x;
                diff_weight[y] = w;
            }
            return true;
        }

        bool same(int x, int y)
        {
            return find(x) == find(y);
        }

        KYOPRO_BASE_INT group_size(int x)
        {
            return -par[find(x)];
        }

        std::vector<int> group_members(int x)
        {
            x = find(x);
            std::vector<int> a;
            for (int i = 0; i < (int)(size()); ++i)
                if (find(i) == x)
                    a.emplace_back(i);
            return a;
        }

        template <class Vector = std::vector<KYOPRO_BASE_INT>>
        Vector roots() const
        {
            Vector a;
            for (int i = 0; i < (int)(size()); ++i)
                if (par[i] < 0)
                    a.emplace_back(i);
            return a;
        }

        KYOPRO_BASE_INT group_count() const
        {
            KYOPRO_BASE_INT cnt = 0;
            for (int i = 0; i < (int)(size()); ++i)
                if (par[i] < 0)
                    ++cnt;
            return cnt;
        }

        template <class Map = std::unordered_map<KYOPRO_BASE_INT, std::vector<KYOPRO_BASE_INT>>>
        Map all_group_members()
        {
            Map group_members;
            for (int member = 0; member < (int)(size()); ++member)
                group_members[find(member)].emplace_back(member);
            return group_members;
        }
    };
} // namespace kpr

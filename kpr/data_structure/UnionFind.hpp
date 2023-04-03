#pragma once
#include <algorithm>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>
#include "../meta/setting.hpp"
#include "../meta/trait.hpp"

namespace kpr {
    struct UnionFind {
    private:
        std::vector<int> par;

    public:
        UnionFind() noexcept = default;
        UnionFind(std::size_t n) noexcept: par(n, -1) {}

        void resize(std::size_t n) {
            par.resize(n, -1);
        }
        void assign(std::size_t n) {
            par.assign(n, -1);
        }
        void clear() {
            std::fill(par.begin(), par.end(), -1);
        }

        std::size_t size() const noexcept {
            return par.size();
        }

        KYOPRO_BASE_INT find(int x) {
            int p = x;
            while (par[p] >= 0) p = par[p];
            while (x != p) {
                int tmp = x;
                x = par[x];
                par[tmp] = p;
            }
            return p;
        }

        bool merge(int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return false;
            if (par[x] > par[y]) {
                par[y] += par[x];
                par[x] = y;
            } else {
                par[x] += par[y];
                par[y] = x;
            }
            return true;
        }

        bool same(int x, int y) {
            return find(x) == find(y);
        }

        KYOPRO_BASE_INT group_size(int x) {
            return -par[find(x)];
        }

        std::vector<int> group_members(int x) {
            x = find(x);
            std::vector<int> a;
            for (int i = 0; i < (int)(size()); ++i) if (find(i) == x) a.emplace_back(i);
            return a;
        }

        template<class Vector = std::vector<KYOPRO_BASE_INT>>
        Vector roots() const {
            Vector a;
            for (int i = 0; i < (int)(size()); ++i) if (par[i] < 0) a.emplace_back(i);
            return a;
        }

        KYOPRO_BASE_INT group_count() const {
            KYOPRO_BASE_INT cnt = 0;
            for (int i = 0; i < (int)(size()); ++i) if (par[i] < 0) ++cnt;
            return cnt;
        }

        template<class Map = std::unordered_map<KYOPRO_BASE_INT, std::vector<KYOPRO_BASE_INT>>>
        Map all_group_members() {
            Map group_members;
            for (int member = 0; member < (int)(size()); ++member) group_members[find(member)].emplace_back(member);
            return group_members;
        }
    };
} // namespace kpr

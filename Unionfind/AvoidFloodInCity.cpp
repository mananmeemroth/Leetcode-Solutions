#include <iostream>
#include <numeric>
#include <set>
#include <unordered_set>
using namespace std;
class UnionFind {
public:
    vector<int> parent;

    UnionFind(int size) : parent(size + 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (i == parent[i])
            return i;
        parent[i] = find(parent[i]);
        return parent[i];
    }

    void unite(int i) { parent[i] = find(i + 1); }
};

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rain) {
        int n = rain.size();
        UnionFind uf(n + 1);
        unordered_map<int, int> map;
        vector<int> res(n, 1);

        for (int i = 0; i < n; i++) {
            int lake = rain[i];
            if (lake == 0) continue;

            res[i] = -1;
            uf.unite(i);

            if (map.find(lake) != map.end()) {
                int prev = map[lake];
                int dry = uf.find(prev + 1);

                if (dry >= i) return {};

                res[dry] = lake;
                uf.unite(dry);
                map[lake] = i;
            } else {
                map[lake] = i;
            }
        }

        return res;
    }
};



// understandable for beginners solution
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> zer;
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> M;

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                zer.insert(i);
                ans[i] = 1;
            } else {
                int lake = rains[i];
                if (M.find(lake) != M.end()) {
                    int lastRainDay = M[lake];
                    auto up = zer.upper_bound(lastRainDay);
                    if (up == zer.end()) {
                        return {};
                    }
                    ans[*up] = lake;
                    zer.erase(up);
                }
                M[lake] = i;
            }
        }
        return ans;
    }
};
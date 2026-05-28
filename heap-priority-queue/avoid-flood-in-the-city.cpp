class UnionFind {
public:
    vector<int> parent;
    UnionFind(int size): parent(size+1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        UnionFind uf(n);
        unordered_map<int, int> lastRain;
        vector<int> res(n, 1);

        for (int i = 0; i < n; i++) {
            int lake = rains[i];
            if (lake > 0) {
                res[i] = -1;
                if (lastRain.count(lake)) {
                    int prev = lastRain[lake];
                    int dry = uf.find(prev + 1);   
                    if (dry >= i) return {};       
                    res[dry] = lake;               
                    uf.unite(dry, dry + 1);
                }
                lastRain[lake] = i;
                uf.unite(i, i + 1);               
            }
        }
        return res;
    }
};

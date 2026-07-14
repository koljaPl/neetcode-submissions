class DSU {
private:
    vector<int> parents;
    vector<int> size;

public:
    DSU(int n) {
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        
        size.assign(n, 1);
    }

    int find(int x) {
        if (parents[x] != x)
            parents[x] = find(parents[x]);
        
        return parents[x];
    }

    bool dsu_union(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return false;
        
        if (size[u] < size[v])
            swap(u, v);

        parents[v] = u;
        size[u] += size[v];

        return true;
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int res = n;

        for (const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            if (dsu.dsu_union(u, v))
                res -= 1;
        }

        return res;
    }
};

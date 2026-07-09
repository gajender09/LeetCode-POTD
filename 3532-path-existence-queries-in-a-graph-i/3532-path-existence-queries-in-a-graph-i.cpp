class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return parent[x];

        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (size[px] < size[py])
            swap(px, py);

        parent[py] = px;
        size[px] += size[py];
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<bool> ans;
        DSU dsu(n);

        for (int i = 1; i < n; i++) {
            
            if (nums[i] - nums[i - 1] <= maxDiff)
                dsu.unite(i, i - 1);
        }

        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];

            ans.push_back(dsu.find(u) == dsu.find(v));
        }

        return ans;
    }
};
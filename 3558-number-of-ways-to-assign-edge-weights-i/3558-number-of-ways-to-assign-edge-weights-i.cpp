class Solution {
public:
    void countEdges(int child, int parent, int currDepth, int& maxDepth,
                    vector<vector<int>>& adj) {
        maxDepth = max(maxDepth, currDepth);

        for (int nei : adj[child]) {
            if (nei == parent)
                continue;

            countEdges(nei, child, currDepth + 1, maxDepth, adj);
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        long long MOD = 1e9 + 7;

        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int maxDepth = 0;

        countEdges(1, -1, 0, maxDepth, adj);

        if (maxDepth == 0)
            return 1;

        long long ways = 1;

        for (int i = 1; i < maxDepth; i++) {
            ways = (ways * 2) % MOD;
        }

        return ways;
    }
};
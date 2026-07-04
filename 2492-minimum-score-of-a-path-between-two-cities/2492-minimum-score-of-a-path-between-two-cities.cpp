class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);

        // build adj list from given adj matrix
        for (auto& e : roads) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // BFS
        vector<int> vis(n + 1, 0);
        queue<int> q;

        q.push(1);
        vis[1] = 1;
        int ans = INT_MAX;

        while (!q.empty()) {
            int p = q.front();
            q.pop();

            for (auto& [v, w] : adj[p]) {
                ans = min(ans, w);

                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};
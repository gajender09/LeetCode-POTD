class Solution {
public:
    using ll = long long;
    const ll INF = 4e18;

    bool check(int limit, vector<vector<pair<int, int>>>& graph, vector<int>& topo, vector<bool>& online, long long k) {

        int n = graph.size();

        vector<ll> dist(n, INF);
        dist[0] = 0;

        for (int u : topo) {

            if (dist[u] == INF)
                continue;

            // Skip offline intermediate nodes
            if (u != 0 && u != n - 1 && !online[u])
                continue;

            for (auto [v, w] : graph[u]) {

                // Ignore weak edges
                if (w < limit)
                    continue;

                // Destination can be offline
                if (v != n - 1 && !online[v])
                    continue;

                dist[v] = min(dist[v], dist[u] + w);
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int, int>>> graph(n);
        vector<int> indegree(n);

        int maxEdge = 0;

        // Build graph
        for (auto& e : edges) {

            int u = e[0];
            int v = e[1];
            int w = e[2];

            graph[u].push_back({v, w});
            indegree[v]++;

            maxEdge = max(maxEdge, w);
        }

        // Topological Sort
        vector<int> topo;
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            topo.push_back(u);

            for (auto [v, w] : graph[u]) {

                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        // Binary Search
        int low = 0;
        int high = maxEdge;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(mid, graph, topo, online, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
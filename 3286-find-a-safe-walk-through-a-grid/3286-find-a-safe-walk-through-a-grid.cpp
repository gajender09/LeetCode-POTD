class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        queue<tuple<int, int, int>> q;               // (row, col, remaining health)
        vector<vector<int>> bestHealth(m, vector<int>(n, -1));

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        q.push({0, 0, startHealth});
        bestHealth[0][0] = startHealth;

        while (!q.empty()) {
            auto [r, c, health] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1)
                return true;

            for (auto &v : dir) {

                int newR = r + v[0];
                int newC = c + v[1];

                if (newR >= 0 && newR < m &&
                    newC >= 0 && newC < n) {

                    int newHealth = health - grid[newR][newC];

                    if (newHealth > 0 && newHealth > bestHealth[newR][newC]) {
                        bestHealth[newR][newC] = newHealth;
                        q.push({newR, newC, newHealth});
                    }
                }
            }
        }

        return false;
    }
};
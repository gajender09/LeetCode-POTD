class Solution {
public:
    int m, n;

    unordered_map<int, vector<vector<int>>> directions = {
        {1, {{0, -1}, {0, 1}}},  
        {2, {{-1, 0}, {1, 0}}},
        {3, {{0, -1}, {1, 0}}},  
        {4, {{0, 1}, {1, 0}}},
        {5, {{0, -1}, {-1, 0}}}, 
        {6, {{-1, 0}, {0, 1}}}
    };

    bool validPathDFS(int i, int j, vector<vector<int>>& grid,
                      vector<vector<int>>& vis) {

        if (i == m - 1 && j == n - 1) {
            return true;
        }
        vis[i][j] = true;

        // accessing neighbours
        for (auto& dir : directions[grid[i][j]]) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n ||
                vis[new_i][new_j]) {
                continue;
            }
            
            // Checking if I come back to i & j from new_i & new_j
            for (auto& backDir : directions[grid[new_i][new_j]]) {
                if (new_i + backDir[0] == i && new_j + backDir[1] == j) {
                    if (validPathDFS(new_i, new_j, grid, vis)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, false));
        //T.C : O(m*n)

        return validPathDFS(0, 0, grid, vis);
    }
};
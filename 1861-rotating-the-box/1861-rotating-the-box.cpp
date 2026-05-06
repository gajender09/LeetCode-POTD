class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> res(n, vector<char>(m));

        // Transpose
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][i] = boxGrid[i][j];
            }
        }

        // Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(res[i].begin(), res[i].end());
        }

        // Apply gravity
        for (int j = 0; j < m; j++) {
            int spaceBottomRow = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (res[i][j] == '*') {
                    spaceBottomRow = i - 1;
                    continue;
                }

                if (res[i][j] == '#') {
                    res[i][j] = '.';
                    res[spaceBottomRow][j] = '#';
                    spaceBottomRow--;
                }
            }
        }
        return res;
    }
};
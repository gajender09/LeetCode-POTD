class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int N = min(m, n) / 2;

        for(int layer = 0; layer < N; layer++){

            vector<int> vec;

            int top = layer;
            int bottom = m - layer - 1;
            int left = layer;
            int right = n - layer - 1;

            //top row
            for(int i = left; i <= right; i++){
                vec.push_back(grid[top][i]);
            }

            //right col
            for(int i = top + 1; i <= bottom - 1; i++){
                vec.push_back(grid[i][right]);
            }

            //bottom row
            for(int i = right; i >= left; i--){
                vec.push_back(grid[bottom][i]);
            }

            //left col
            for(int i = bottom - 1; i >= top + 1; i--){
                vec.push_back(grid[i][left]);
            }

            int size = vec.size();
            int newk = k % size;
            //rotate vec by k
            rotate(begin(vec), begin(vec) + newk, end(vec));

            int idx = 0;

            for(int i = left; i <= right; i++){
                grid[top][i] = vec[idx];
                idx++;
            }

            for(int i = top + 1; i < bottom; i++){
                grid[i][right] = vec[idx];
                idx++;
            }

            for(int i = right; i >= left; i--){
                grid[bottom][i] = vec[idx];
                idx++;
            }

            for(int i = bottom - 1; i > top; i--){
                grid[i][left] = vec[idx];
                idx++;
            }
        }

        return grid;
    }
};
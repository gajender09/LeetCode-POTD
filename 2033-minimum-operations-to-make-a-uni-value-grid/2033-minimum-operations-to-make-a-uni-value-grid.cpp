class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flat;

        for (auto &row : grid) {
            for (auto &num : row) {
                flat.push_back(num);
            }
        }

        sort(flat.begin(), flat.end());

        int median = flat[flat.size() / 2];
        int minOps = 0;

        for (int num : flat) {
            if (abs(num - median) % x != 0)
                return -1;

            minOps += abs(num - median) / x;
        }

        return minOps;
    }
};
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixSum(n, 0);
        vector<int> suffixSum(n, 0);
        vector<int> res(n);

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];

            int j = n - i - 1;
            suffixSum[j] = suffixSum[j + 1] + nums[j + 1];
        }

        for (int k = 0; k < n; k++) {
            res[k] = abs(prefixSum[k] - suffixSum[k]);
        }

        return res;
    }
};
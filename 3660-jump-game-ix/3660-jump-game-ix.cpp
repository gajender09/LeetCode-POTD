class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxPrefix(n);
        vector<int> minSuffix(n);
        vector<int> ans(n);

        maxPrefix[0] = nums[0];
        minSuffix[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            int maxVal = max(maxPrefix[i - 1], nums[i]);
            maxPrefix[i] = maxVal;
        }

        for (int i = n - 2; i >= 0; i--) {
            int minVal = min(minSuffix[i + 1], nums[i]);
            minSuffix[i] = minVal;
        }

        ans[n - 1] = maxPrefix[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            if (maxPrefix[i] > minSuffix[i + 1]) {
                ans[i] = ans[i + 1];
            } else {
                ans[i] = maxPrefix[i];
            }
        }

        return ans;
    }
};
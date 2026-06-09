class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxEle = INT_MIN;
        int minEle = INT_MAX;

        for (int num : nums) {
            maxEle = max(maxEle, num);
            minEle = min(minEle, num);
        }

        return 1LL * k * (maxEle - minEle);
    }
};
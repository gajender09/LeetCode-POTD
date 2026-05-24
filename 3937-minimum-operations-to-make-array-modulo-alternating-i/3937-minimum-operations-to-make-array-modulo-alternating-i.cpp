class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y) continue;

                int ops = 0;

                // even indices
                for (int i = 0; i < n; i += 2) {
                    int rem = nums[i] % k;

                    int inc = (x - rem + k) % k;
                    int dec = (rem - x + k) % k;

                    ops += min(inc, dec);
                }

                // odd indices
                for (int i = 1; i < n; i += 2) {
                    int rem = nums[i] % k;

                    int inc = (y - rem + k) % k;
                    int dec = (rem - y + k) % k;

                    ops += min(inc, dec);
                }

                ans = min(ans, ops);
            }
        }

        return ans;
    }
};
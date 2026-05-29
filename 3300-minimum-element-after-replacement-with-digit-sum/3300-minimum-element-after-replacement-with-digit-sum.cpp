class Solution {
public:
    int minElement(vector<int>& nums) {

        int n = nums.size();
        int res = INT_MAX;

        for (int num : nums) {
            int sum = 0;
            while (num > 0) {
                sum += (num % 10);
                num /= 10;
            }
            res = min(res, sum);
        }

        return res;
    }
};
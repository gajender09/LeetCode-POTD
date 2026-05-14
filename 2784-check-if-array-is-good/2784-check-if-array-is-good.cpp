class Solution {
public:
    bool isGood(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        for (int i = 1; i <= n - 2; i++) {
            if (freq[i] == 1)
                continue;

            return false;
        }

        return freq[n - 1] == 2;
    }
};
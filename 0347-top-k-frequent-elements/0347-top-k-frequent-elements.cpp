class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int, int> freq;
        vector<vector<int>> bucket(n + 1);

        for (int num : nums) {
            freq[num]++;
        }

        for (auto& p : freq) {
            int ele = p.first;
            int count = p.second;
            bucket[count].push_back(ele);
        }

        vector<int> res;

        for (int i = n; i >= 0 && res.size() < k; i--) {
            for (int num : bucket[i]) {
                res.push_back(num);

                if (res.size() == k)
                    return res;
            }
        }

        return res;
    }
};
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        vector<long long> res(n, 0);

        // store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // process each group
        for (auto &p : mp) {
            vector<int>& v = p.second;

            long long totalSum = 0;
            for (int x : v) totalSum += x;

            long long leftSum = 0, rightSum = totalSum;
            long long leftCount = 0, rightCount = v.size();

            for (int i = 0; i < v.size(); i++) {
                rightSum -= v[i];
                rightCount--;

                long long left = leftCount * 1LL * v[i] - leftSum;
                long long right = rightSum - rightCount * 1LL * v[i];

                res[v[i]] = left + right;

                leftSum += v[i];
                leftCount++;
            }
        }

        return res;
    }
};
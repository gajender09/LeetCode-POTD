class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        vector<long long> res(n, 0);

        // store indices of each value
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // process each group
        for (auto &p : mp) {
            vector<int>& v = p.second;
            int sz = v.size();

            // prefix sum of indices
            vector<long long> pref(sz, 0);
            pref[0] = v[0];

            for (int i = 1; i < sz; i++) {
                pref[i] = pref[i - 1] + v[i];
            }

            for (int i = 0; i < sz; i++) {
                long long left = 0, right = 0;

                if (i > 0) {
                    left = 1LL * i * v[i] - pref[i - 1];
                }

                if (i < sz - 1) {
                    right = (pref[sz - 1] - pref[i]) -
                            1LL * (sz - i - 1) * v[i];
                }

                res[v[i]] = left + right;
            }
        }

        return res;
    }
};
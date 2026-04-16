class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // store indices of each value
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> best(n, INT_MAX);

        // process each value group
        for (auto &p : mp) {
            auto &v = p.second;
            int sz = v.size();

            if (sz == 1) continue;

            for (int i = 0; i < sz; i++) {
                int curr = v[i];
                int prev = v[(i - 1 + sz) % sz];
                int next = v[(i + 1) % sz];

                int d1 = abs(curr - prev);
                int d2 = abs(curr - next);

                // circular distance
                d1 = min(d1, n - d1);
                d2 = min(d2, n - d2);

                best[curr] = min(d1, d2);
            }
        }

        // answer queries
        vector<int> res;
        for (int q : queries) {
            if (best[q] == INT_MAX) res.push_back(-1);
            else res.push_back(best[q]);
        }

        return res;
    }
};
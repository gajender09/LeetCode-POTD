class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);

        vector<pair<int, int>> order;

        for (int i = 0; i < n; i++) {
            order.push_back({arr[i], i});
        }

        sort(begin(order), end(order));

        for (auto& it : order) {
            int val = it.first;
            int i = it.second;

            int result = 1;

            // left
            for (int j = i - 1; j >= max(0, i - d); j--) {
                if (arr[j] >= arr[i])
                    break;

                result = max(result, 1 + dp[j]);
            }

            // right
            for (int j = i + 1; j <= min(n - 1, i + d); j++) {
                if (arr[j] >= arr[i])
                    break;

                result = max(result, 1 + dp[j]);
            }

            dp[i] = result;
        }

        return *max_element(begin(dp), end(dp));
    }
};
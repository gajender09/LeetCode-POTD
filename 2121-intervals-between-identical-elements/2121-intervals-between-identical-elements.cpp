class Solution {
public:

    typedef long long ll;

    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();

        vector<ll> res(n, 0);

        unordered_map<int, ll> indexSum;   // nums[i] -> sum of i's
        unordered_map<int, ll> indexCount; // nums[i] -> frequency

        // Left to Right
        for (int i = 0; i < n; i++) {
            ll freq = indexCount[arr[i]];
            ll sum = indexSum[arr[i]];

            res[i] += freq * i - sum;

            indexCount[arr[i]] += 1;
            indexSum[arr[i]] += i;
        }

        indexSum.clear();
        indexCount.clear();

        // Right to Left
        for (int i = n - 1; i >= 0; i--) {
            ll freq = indexCount[arr[i]];
            ll sum = indexSum[arr[i]];

            res[i] += sum - freq * i;

            indexCount[arr[i]] += 1;
            indexSum[arr[i]] += i;
        }

        return res;
    }
};
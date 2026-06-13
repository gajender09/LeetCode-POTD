class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {

        string ans = "";

        for (auto& str : words) {
            int sum = 0;

            for (char ch : str) {
                sum += weights[ch - 'a'];
            }

            int mod = sum % 26;

            ans += 'z' - mod;
        }

        return ans;
    }
};
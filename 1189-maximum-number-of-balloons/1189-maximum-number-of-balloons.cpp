class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char, int> freq;

        for (char ch : text) {
            freq[ch]++;
        }

        int ans = INT_MAX;

        ans = min(ans, freq['b']);
        ans = min(ans, freq['a']);
        ans = min(ans, freq['n']);
        ans = min(ans, freq['l'] / 2);
        ans = min(ans, freq['o'] / 2);

        return ans;
    }
};
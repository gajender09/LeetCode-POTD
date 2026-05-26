class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int, pair<int, int>> mp;
        int ans = 0;

        for (char ch : word) {

            if (ch >= 'a' && ch <= 'z') {
                mp[ch - 'a'].first++;
            }
            if (ch >= 'A' && ch <= 'Z') {
                mp[tolower(ch) - 'a'].second++;
            }
        }

        for (auto& p : mp) {
            if (p.second.first > 0 && p.second.second > 0) {
                ans++;
            }
        }

        return ans;
    }
};
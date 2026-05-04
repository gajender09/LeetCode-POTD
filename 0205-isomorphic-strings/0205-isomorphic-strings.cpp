class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        unordered_map<char, char> mpST;
        unordered_map<char, char> mpTS;

        for (int i = 0; i < n; i++) {
            char ch1 = s[i];
            char ch2 = t[i];

            if (mpST.find(ch1) != mpST.end() && mpST[ch1] != ch2 ||
                mpTS.find(ch2) != mpTS.end() && mpTS[ch2] != ch1) {
                return false;
            }

            mpST[ch1] = ch2;
            mpTS[ch2] = ch1;
        }

        return true;
    }
};
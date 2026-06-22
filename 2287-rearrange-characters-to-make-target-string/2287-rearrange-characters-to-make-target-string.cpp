class Solution {
public:
    int rearrangeCharacters(string s, string target) {

        vector<int> freqS(26, 0);
        vector<int> freqT(26, 0);

        for(char ch : s) {
            freqS[ch - 'a']++;
        }

        for(char ch : target) {
            freqT[ch - 'a']++;
        }

        int ans = INT_MAX;

        for(int i = 0; i < 26; i++) {

            if(freqT[i] > 0) {
                ans = min(ans, freqS[i] / freqT[i]);
            }
        }

        return ans;
    }
};
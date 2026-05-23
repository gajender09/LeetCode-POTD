class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        string res = "";

        if (numRows == 1)
            return s;

        for (int i = 0; i < numRows; i++) {

            int jump = (numRows - 1) * 2;

            for (int j = i; j < n; j += jump) {

                res += s[j];
                if (i > 0 && i < numRows - 1 && j + jump - 2 * i < n) {
                    res += s[j + jump - 2 * i];
                }
            }
        }

        return res;
    }
};
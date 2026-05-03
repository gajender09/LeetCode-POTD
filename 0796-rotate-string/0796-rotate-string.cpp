class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        string str1 = s;
        string str2 = s;

        while (n--) {
            str1.erase(0, 1);
            char ch = str2[0];
            str1.push_back(ch);

            if (str1 == goal)
                return true;

            str2 = str1;
        }
        return false;
    }
};
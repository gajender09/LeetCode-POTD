class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> res;

        for (string& s : queries) {
            for (string& str : dictionary) {
                int edits = 0;

                for (int i = 0; i < s.length(); i++) {
                    if (s[i] != str[i])
                        edits++;

                    if (edits > 2)
                        break;
                }

                if (edits <= 2) {
                    res.push_back(s);
                    break;
                }
            }
        }

        return res;
    }
};
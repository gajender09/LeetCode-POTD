class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m = target.size();
        vector<string> res;

        int curr = 1;

        for (int i = 0; i < m; i++) {

            if (target[i] == curr) {
                res.push_back("Push");
                curr++;
            } 

            else {
                res.push_back("Push");
                res.push_back("Pop");
                curr++;
                i--;
            }
        }

        return res;
    }
};
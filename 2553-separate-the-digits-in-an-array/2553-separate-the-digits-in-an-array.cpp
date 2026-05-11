class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {

        vector<int> res;

        for (int num : nums) {

            string str = to_string(num);

            for (char ch : str) {

                int val = ch - '0';

                res.push_back(val);
            }
        }
        
        return res;
    }
};
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int d = INT_MAX;
        if(n < 3) return -1;

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        for(auto &pair : mp){
            vector<int>& res = pair.second;
            int x = res.size();

            if(x >= 3){
                for(int i = 0; i + 2 < x; i++){
                    int a = res[i];
                    int b = res[i+1];
                    int c = res[i+2];

                    d = min(d, abs(a - b) + abs(b - c) + abs(c - a));
                }
            }
        }

        return d == INT_MAX ? -1 : d;
    }
};
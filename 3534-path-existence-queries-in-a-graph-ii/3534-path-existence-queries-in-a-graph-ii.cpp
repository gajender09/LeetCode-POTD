class Solution {
public:
    vector<int> pathExistenceQueries(int n,
                                     vector<int>& nums,
                                     int maxDiff,
                                     vector<vector<int>>& queries) {

        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        const int LOG = 20;

        vector<vector<int>> jump(n, vector<int>(LOG));

        int r = n - 1;

        // Build first jump
        for(int l=n-1;l>=0;l--){

            while(arr[r].first-arr[l].first>maxDiff)
                r--;

            jump[arr[l].second][0]=arr[r].second;
        }

        // Binary lifting
        for(int k=1;k<LOG;k++){
            for(int i=0;i<n;i++){
                jump[i][k]=jump[jump[i][k-1]][k-1];
            }
        }

        vector<int> ans;

        for(auto &q:queries){

            int u=q[0];
            int v=q[1];

            if(nums[u]>nums[v])
                swap(u,v);

            if(u==v){
                ans.push_back(0);
                continue;
            }

            if(nums[u]==nums[v]){
                ans.push_back(1);
                continue;
            }

            int steps=0;

            for(int k=LOG-1;k>=0;k--){

                int nxt=jump[u][k];

                if(nums[nxt]<nums[v]){
                    steps+=(1<<k);
                    u=nxt;
                }
            }

            if(nums[jump[u][0]]<nums[v])
                ans.push_back(-1);
            else
                ans.push_back(steps+1);
        }

        return ans;
    }
};
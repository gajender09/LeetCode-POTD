class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();
        queue<int> q;
        vector<bool> vis(n, false);

        q.push(start);
        vis[start] = true;

        while (!q.empty()) {

            int i = q.front();
            vis[i] = true;
            q.pop();

            if (arr[i] == 0)
                return true;

            if (i + arr[i] < n && !vis[i + arr[i]]) {
                q.push(i + arr[i]);
                vis[i + arr[i]] = true;
            }

            if (i - arr[i] >= 0 && !vis[i - arr[i]]) {
                q.push(i - arr[i]);
                vis[i - arr[i]] = true;
            }
        }

        return false;
    }
};
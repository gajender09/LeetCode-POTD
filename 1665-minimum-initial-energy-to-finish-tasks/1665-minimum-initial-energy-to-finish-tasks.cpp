class Solution {
public:

    bool canFinish(vector<vector<int>>& tasks, int energy) {

        int check = energy;

        for (auto& v : tasks) {

            int actual = v[0];
            int minimum = v[1];

            if (check >= minimum) {
                check -= actual;
            } 
            else {
                return false;
            }
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {

        int lower = 1;
        int higher = 0;
        int ans = 0;

        for (auto& v : tasks) {
            higher += v[1];
        }

        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        while (lower <= higher) {

            int mid = lower + (higher - lower) / 2;

            if (canFinish(tasks, mid)) {

                ans = mid;
                higher = mid - 1;

            } 
            else {

                lower = mid + 1;
            }
        }

        return ans;
    }
};
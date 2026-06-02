class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = INT_MAX;

        // Land -> Water
        for (int i = 0; i < n; i++) {
            int landFinish = landStartTime[i] + landDuration[i];

            for (int j = 0; j < m; j++) {
                int waterStart = max(landFinish, waterStartTime[j]);
                ans = min(ans, waterStart + waterDuration[j]);
            }
        }

        // Water -> Land
        for (int i = 0; i < m; i++) {
            int waterFinish = waterStartTime[i] + waterDuration[i];

            for (int j = 0; j < n; j++) {
                int landStart = max(waterFinish, landStartTime[j]);
                ans = min(ans, landStart + landDuration[j]);
            }
        }

        return ans;
    }
};
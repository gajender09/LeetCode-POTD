class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        int res = INT_MAX;

        for (int i = 0; i < n; i++) {

            int landFinish = landStartTime[i] + landDuration[i];

            for (int j = 0; j < m; j++) {

                res = min(res, max(landFinish, waterStartTime[j]) + waterDuration[j]);

                int waterFinish = waterStartTime[j] + waterDuration[j];

                res = min(res, max(waterFinish, landStartTime[i]) + landDuration[i]);
            }
        }

        return res;
    }
};
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currAlt = 0;
        int maxAlt = 0;

        for (int alt : gain) {

            currAlt += alt;

            maxAlt = max(maxAlt, currAlt);
        }

        return maxAlt;
    }
};
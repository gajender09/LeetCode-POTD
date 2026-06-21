class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        sort(begin(costs), end(costs));
        int maxBars = 0;

        for (int i = 0; i < costs.size(); i++) {
            if (costs[i] <= coins) {
                maxBars++;
                coins -= costs[i];

                if(coins == 0) break;
            }
        }

        return maxBars;
    }
};
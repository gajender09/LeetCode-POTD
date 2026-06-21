class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        int maxCost = *max_element(costs.begin(), costs.end());

        vector<int> freq(maxCost + 1);

        // Count each cost
        for (int cost : costs) {
            freq[cost]++;
        }

        int ans = 0;

        // Traverse costs from cheapest to expensive
        for (int price = 1; price <= maxCost && coins >= price; price++) {

            int canBuy = min(freq[price], coins / price);

            ans += canBuy;
            coins -= canBuy * price;
        }

        return ans;
    }
};
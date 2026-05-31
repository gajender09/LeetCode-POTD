class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        bool ans = false;

        long long m = mass;

        sort(begin(asteroids), end(asteroids));

        for (int asteroid : asteroids) {
            if (m >= asteroid) {
                m += asteroid;
            } 
            else {
                return ans;
            }
        }
        ans = true;

        return ans;
    }
};
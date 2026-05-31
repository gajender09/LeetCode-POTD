class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m = mass;

        sort(begin(asteroids), end(asteroids));

        for (int &asteroid : asteroids) {
            if (m >= asteroid) {
                m += asteroid;
            } 
            else {
                return false;
            }
        }

        return true;
    }
};
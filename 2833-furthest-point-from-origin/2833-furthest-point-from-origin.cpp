class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0;
        int R = 0;
        int underscore = 0;

        for (char ch : moves) {
            if (ch == 'L')
                L++;
            else if (ch == 'R')
                R++;
            else
                underscore++;
        }
        return abs(L - R) + underscore;
    }
};
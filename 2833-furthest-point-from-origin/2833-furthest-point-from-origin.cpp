class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0;
        int R = 0;
        int B = 0;

        for (char ch : moves) {
            if (ch == 'L')
                L++;
            else if (ch == 'R')
                R++;
            else
                B++;
        }
        return abs(L - R) + B;
    }
};
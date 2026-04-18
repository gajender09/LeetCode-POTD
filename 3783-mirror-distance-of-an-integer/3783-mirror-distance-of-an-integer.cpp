class Solution {
public:
    int getReverse(int n) {
        int rev = 0;
        while (n > 0) {
            int rem = n % 10;
            rev = rev * 10 + rem;
            n /= 10;
        }
        return rev;
    }

    int mirrorDistance(int n) {
        int rev = getReverse(n);
        return abs(n - rev);
    }
};
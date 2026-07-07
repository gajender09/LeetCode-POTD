class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;

        long long num = 0;
        long long place = 1;
        int sum = 0;

        while (n) {
            int digit = n % 10;

            if (digit) {
                num += 1LL * digit * place;
                place *= 10;
                sum += digit;
            }

            n /= 10;
        }

        return num * sum;
    }
};
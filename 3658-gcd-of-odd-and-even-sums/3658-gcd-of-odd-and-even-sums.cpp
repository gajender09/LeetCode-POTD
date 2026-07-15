class Solution {
public:
    int gcdOfOddEvenSums(int n) {

        int sumOdd = 0;
        int sumEven = 0;

        for (int num = 1; num <= 2 * n; num++) {
            if (num % 2 == 0)
                sumEven += num;

            else
                sumOdd += num;
        }

        return gcd(sumOdd, sumEven);
    }
};
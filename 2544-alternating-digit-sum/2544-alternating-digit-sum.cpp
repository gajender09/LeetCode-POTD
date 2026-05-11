class Solution {
public:
    int alternateDigitSum(int n) {

        int sum = 0;
        int idx = 0;

        string s = to_string(n);

        reverse(begin(s), end(s));

        n = stoi(s);

        while (n > 0) {

            int rem = n % 10;

            n /= 10;

            if (idx++ % 2 == 0) {
                sum += rem;
            } 
            else
                sum -= rem;
        }

        return sum;
    }
};
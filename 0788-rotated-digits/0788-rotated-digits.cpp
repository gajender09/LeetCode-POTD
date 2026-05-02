class Solution {
public:
    vector<int> t;
    int solve(int num) {
        if (t[num] != -1)
            return t[num];
        if (num == 0) {
            return t[num] = 0;
        }

        int remain = solve(num / 10);
        if (remain == 2)
            return t[num] = 2;
            
        int digit = num % 10;
        int digit_check;

        if (digit == 0 || digit == 1 || digit == 8)
            digit_check = 0;

        else if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
            digit_check = 1;

        else
            return t[num] = 2;

        if (digit_check == 0 && remain == 0)
            return t[num] = 0;

        return t[num] = 1;
    }

    int rotatedDigits(int n) {
        int count = 0;
        t.resize(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            if (solve(i) == 1) {
                count++;
            }
        }

        return count;
    }
};
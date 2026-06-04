class Solution {
public:
    int countWavy(string str) {
        int l = str.length();
        if (l < 3)
            return 0;

        int total = 0;

        for (int i = 1; i <= l - 2; i++) {
            if (str[i] > str[i - 1] && str[i] > str[i + 1])
                total++;

            else if (str[i] < str[i - 1] && str[i] < str[i + 1])
                total++;
        }
        return total;
    }

    int totalWaviness(int num1, int num2) {

        int ans = 0;

        for (int i = num1; i <= num2; i++) {
            string s = to_string(i);
            ans += countWavy(s);
        }

        return ans;
    }
};
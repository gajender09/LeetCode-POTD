class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string s2;

        if(s == "0") return 0;

        int sum = 0;

        for (char ch : s) {
            if (ch == '0')
                continue;

            s2 += ch;
            sum += ch - '0';
        }

        int x = stoi(s2);

        return 1LL * x * sum;
    }
};
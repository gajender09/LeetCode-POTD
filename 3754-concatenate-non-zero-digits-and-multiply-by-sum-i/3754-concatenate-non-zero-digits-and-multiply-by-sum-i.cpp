class Solution {
public:
    long long sumAndMultiply(int n) {

        if(n == 0) return 0;

        string s = to_string(n);

        long long x = 0;
        int sum = 0;

        for(char ch : s){
            if(ch == '0') continue;

            int d = ch - '0';
            x = x * 10 + d;
            sum += d;
        }

        return x * sum;
    }
};
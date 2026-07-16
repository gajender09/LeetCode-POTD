class Solution {
public:
    long long gcdSum(vector<int>& A) {
        int mx = 0;

        for (auto& n : A) {
            mx = max(mx, n);
            n = gcd(n, mx);
        }

        sort(begin(A), end(A));

        long long ans = 0;
        
        for (int i = 0, j = A.size() - 1; i < j; i++, j--)
            ans += gcd(A[i], A[j]);

        return ans;
    }
};
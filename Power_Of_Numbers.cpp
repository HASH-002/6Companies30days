class Solution {
   public:
    long long power(int n, int r) {
        if (r == 0)
            return 1;
        if (r == 1)
            return n;
        long long ans = power(n, r / 2) % mod;
        ans = (ans * ans) % mod;
        if (r % 2 == 1)
            return (ans * n) % mod;
        return ans;
    }
};
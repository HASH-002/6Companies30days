class Solution {
   public:
    int dp[201][201];
    int solve(int i, int n) {
        if (i >= n)
            return 0;
        if (dp[i][n] != -1)
            return dp[i][n];

        int ans = INT_MAX;
        for (int k = i; k <= n; k++) {
            int temp = k + max(solve(i, k - 1), solve(k + 1, n));
            ans = min(temp, ans);
        }
        return dp[i][n] = ans;
    }
    int getMoneyAmount(int n) {
        memset(dp, -1, sizeof dp);
        return solve(1, n);
    }
};
class Solution {
   public:
    int dp[16][16];
    int solve(int n, int m, int i, int j) {
        if (i == n - 1 || j == m - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = solve(n, m, i + 1, j) + solve(n, m, i, j + 1);
    }
    int NumberOfPath(int a, int b) {
        memset(dp, -1, sizeof dp);
        return solve(a, b, 0, 0);
    }
};
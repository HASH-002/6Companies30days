class Solution {
   public:
    int maxProfit(int k, int n, int a[]) {
        int dp[k + 1][n];
        for (int i = 0; i <= k; i++) {
            int maximum = INT_MIN;
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else {
                    maximum = max(dp[i - 1][j - 1] - a[j - 1], maximum);
                    dp[i][j] = max(dp[i][j - 1], maximum + a[j]);
                }
            }
        }
        return dp[k][n - 1];
    }
};
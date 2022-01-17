class Solution
{
  public:
    long long mod = 1000000007;
    long long dp[1001][1001];
    long long solve(int n, int k, int K){
        if(n==0)
            return 1;
        
        if(dp[n][k]!=-1) 
            return dp[n][k];
        
        long long res1 = (solve(n-1,K,K)*21)%mod;
        if(k>0){
            long long res2 = (solve(n-1,k-1,K)*5)%mod;
            res1 = (res1+res2)%mod;
        }
        return dp[n][k] = res1;
    }
    int kvowelwords(int n, int K) {
        memset(dp,-1,sizeof dp);
        return solve(n,K,K);
    }
};
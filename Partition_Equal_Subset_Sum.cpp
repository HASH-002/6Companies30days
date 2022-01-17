class Solution{
public:
    int equalPartition(int n, int a[])
    {
        long sum = accumulate(a,a+n,0);
        if(sum%2==1)
            return false;
        
        sum /= 2;
        bool dp[n+1][sum+1];
        memset(dp, false, sizeof dp);
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=sum;j++){
                if(j==0)
                    dp[i][j]=true;
                else if(i==0)
                    dp[i][j]=false;
                else if(j>=a[i-1])
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        return dp[n][sum];
    }
};
class Solution {
public:
    int dp[501][501];
    int solve(vector<int>&a,int i, int j){
        if(i>j)
            return dp[i][j]=0;
        if(i==j)
            return dp[i][j]=a[i];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int l = a[i]+ min(solve(a,i+1,j-1),solve(a,i+2,j));
        int r = a[j]+ min(solve(a,i+1,j-1),solve(a,i,j-2));
        return dp[i][j]=max(l,r);
    }
    int maxCoins(vector<int>&a,int n)
    {
        memset(dp,-1,sizeof dp);
	    return solve(a,0,n-1);
    }
};
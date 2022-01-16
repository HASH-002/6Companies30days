class Solution{   
public:
    int lengthOfLongestAP(int a[], int n) {
        if(n<=2)
            return n;
        int ans = 2;
        unordered_map<int,int>dp[n];
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = a[i]-a[j];
                dp[i][diff] = dp[j].find(diff)!=dp[j].end() ? dp[j][diff]+1 : 2;
                ans = max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};
class Solution{
public:
    int dp[501][501];
    int brackets[501][501];
    void bracketString(int i, int j, string&s){
        if(i==j){
            s+='A'+j-1;
            return;
        }
        s+='(';
        bracketString(i,brackets[i][j],s);
        bracketString(brackets[i][j]+1,j,s);
        s+=')';
    }
    int solve(int a[], int i, int j){
        if(i==j){
            brackets[i][j]=j;
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = INT_MAX;
        int point = 0;
        for(int k=i;k<j;k++){
            int temp = solve(a,i,k)+solve(a,k+1,j)+a[i-1]*a[k]*a[j];
            if(temp<ans){
                ans = temp;
                point = k;
            }
        }
        brackets[i][j] = point;
        return dp[i][j] = ans;
    }
    string matrixChainOrder(int a[], int n){
        if(n==2)
            return "A";
        
        memset(dp, -1, sizeof dp);
        solve(a,1,n-1);
        
        string ans="";
        bracketString(1,n-1,ans);
        return ans;
    }
};
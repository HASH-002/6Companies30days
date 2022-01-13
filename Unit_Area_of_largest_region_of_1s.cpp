class Solution
{
    public:
    int solve(vector<vector<int>>&a, int i, int j){
        if(i<0 || j<0 || i>=a.size() || j>=a[0].size() || a[i][j]==0)
            return 0;
        
        a[i][j]=0;
        
        int r = solve(a,i+1,j);
        int u = solve(a,i,j+1);
        int d = solve(a,i,j-1);
        int l = solve(a,i-1,j);
        
        int b = solve(a,i+1,j+1);
        int c = solve(a,i+1,j-1);
        int e = solve(a,i-1,j+1);
        int f = solve(a,i-1,j-1);
        
        int temp = 1+l+u+d+r+f+b+c+e;
        return temp;
    }
    int findMaxArea(vector<vector<int>>&a) {
        int n = a.size();
        int m = a[0].size();
        int ans = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(a[i][j]!=0)
                    ans = max(ans,solve(a,i,j));
        
        return ans;
    }
};
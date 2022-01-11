class Solution{
  public:
	int minDifference(int a[], int n)  { 
	    int sum = accumulate(a,a+n,0);
	    bool dp[n+1][sum+1];
	    
	    for(int i=0;i<=n;i++){
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
	    }
	    int s=0;
	    for(int k=sum/2;k>=0;k--)
	        if(dp[n][k]){
	            s=k;
	            break;
	        }
	    return sum-2*s;
	} 
};
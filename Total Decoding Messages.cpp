class Solution {
	public:
		int CountWays(string s){
		    if(s[0]=='0')
		        return 0;
		    if(s.length()==1)
		        return 1;
		        
		    long long mod = 1000000007;
		    int n = s.length();
		    int dp[n];
		    dp[0] = 1;
		    
		    if(s[1]=='0'){
		        dp[1]=0;
		        if(s[0]=='1' || s[0]=='2')
		            dp[1]=1;
		    }else{
		        dp[1] = 1;
		        if(s[0]=='1' || s[0]=='2' && s[1]<='6')
		            dp[1] = 2;
		    }
		    
		    for(int i=2;i<n;i++){
		        if(s[i]=='0'){
		            dp[i]=0;
    		        if(s[i-1]=='1' || s[i-1]=='2')
    		            dp[i]=dp[i-2];
		        }else{
		            dp[i] = dp[i-1];
		            if(s[i-1]=='1' || s[i-1]=='2' && s[i]<='6')
		                dp[i] = (dp[i] + dp[i-2])%mod;
		        }
		    }
		    return dp[n-1];
		}

};
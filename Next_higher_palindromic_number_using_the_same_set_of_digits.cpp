class Solution{
  public:
    string nextPalin(string s) {
        if(s.length()<=3)
            return "-1";
        
        int n = s.length();
        string temp = "";
        for(int i=0;i<n/2;i++)
            temp += s[i];
        
        // Computing next permutation of ans
        string ans = temp;
        int l = ans.length();
        int j=l-1;
        while(j>0 && ans[j]<=ans[j-1])
            j--;
        
        if(j==0)
            reverse(ans.begin(),ans.begin()+l);
        else{
            int i = j-1;
            j=l-1;
            while(j>i && ans[i]>=ans[j])
                j--;
            
            swap(ans[i],ans[j]);
            reverse(ans.begin()+i+1,ans.begin()+l);
        }
        
        if(ans<=temp)
            return "-1";
        
        temp = ans;
        if(n%2==1)
            ans += s[n/2];
        
        reverse(temp.begin(),temp.end());
        ans+=temp;
        return ans;
    }
};
class Solution{   
public:
    string printMinNumberForPattern(string s){
        string ans="1";
        int n=s.length();
        for(int i=0;i<n;i++)
            ans.push_back(i+2+'0');
        
        int i=0,j=1,k=0;
        while(k<n){
            if(s[k]=='I'){
                reverse(ans.begin()+i,ans.begin()+j);
                i=j;
            }
            j++;
            k++;
        }
        
        if(s[n-1]=='D')
            reverse(ans.begin()+i,ans.begin()+j);
            
        return ans;
    }
};
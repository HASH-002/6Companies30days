class Solution
{
    public:
    void solve(vector<string>&ans, string s, int n, int open, int close){
        if(s.length()==n*2) ans.push_back(s);
        if(open<n) solve(ans,s+'(',n,open+1,close);
        if(close<open) solve(ans,s+')',n,open,close+1);
    }
    vector<string> AllParenthesis(int n){
        vector<string>ans;
        string s="";
        solve(ans,s,n,0,0);
        return ans;
    }
};
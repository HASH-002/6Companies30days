class Solution
{
    public:
    void solve(int a[], int n, int i, vector<string>&ans, string m[], string s){
        if(i==n){
            ans.push_back(s);
            return;
        }
        for(int j=0;j<m[a[i]].length();j++){
            s.push_back(m[a[i]][j]);
            solve(a,n,i+1,ans,m,s);
            s.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int n)
    {
        vector<string>ans;
        string s="";
        string m[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(a,n,0,ans,m,s);
        return ans;
    }
};
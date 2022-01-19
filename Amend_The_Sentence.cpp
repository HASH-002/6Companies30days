class Solution{
    public:
    string amendSentence (string s)
    {
        int i=0;
        string ans;
        while(i<s.length()){
            ans.push_back(tolower(s[i++]));
            while(i<s.length() && s[i]>'Z')
                ans.push_back(s[i++]);
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};
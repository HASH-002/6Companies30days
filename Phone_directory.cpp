class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        set<string>a;
        for(int i=0;i<n;i++)
            a.insert(contact[i]);
        
        vector<vector<string>>ans;
        vector<string>v;
        for(auto i=a.begin();i!=a.end();i++)
            if((*i)[0]==s[0])
                v.push_back(*i);
        if(v.empty())
            v.push_back("0");        
        ans.push_back(v);
        
        for(int i=1;i<s.length();i++){
            vector<string>v;
            for(int j=0;j<ans.back().size();j++)
                if(ans.back()[j][i]==s[i])
                    v.push_back(ans.back()[j]);
            if(v.empty())
                v.push_back("0");
            ans.push_back(v);
        }
        return ans;
    }
};
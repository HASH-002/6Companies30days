class Solution{
  public:
    vector<vector<string>> Anagrams(vector<string>&a) {
        vector<vector<string>>v;
        unordered_map<string,vector<string>>m;
        
        for(int i=0;i<a.size();i++){
            string s= a[i];
            sort(s.begin(),s.end());
            m[s].push_back(a[i]);
        }
        
        for(auto i=m.begin();i!=m.end();i++)
            v.push_back(i->second);
        
        return v;
    }
};
class Solution{
  public:
    vector<string> winner(string s[],int n)
    {
        unordered_map<string,int>m;
        for(int i=0;i<n;i++)
            m[s[i]]++;
        
        vector<string>v;
        v.push_back(m.begin()->first);
        int mx = m.begin()->second;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second>mx){
                mx = it->second;
                v[0] = it->first;
            }else if(it->second == mx && it->first < v[0])
                v[0] = it->first;
        }
        v.push_back(to_string(mx));
        return v;
    }
};
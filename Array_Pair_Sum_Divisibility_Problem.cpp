class Solution {
  public:
    bool canPair(vector<int> a, int k) {
        int n = a.size();
        if(n%2!=0)
            return false;
        
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
            m[a[i]%k]++;
        if(m[0]%2!=0)
            return false;
            
        int i=1,j=k-1;
        while(i<j){
            if(m[i]!=m[j])
                return false;
            i++;
            j--;
        }
        if(i==j && m[0]%2!=0)
            return false;
                
        return true;
    }
};
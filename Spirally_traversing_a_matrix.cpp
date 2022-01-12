class Solution
{   
    public:
    vector<int> spirallyTraverse(vector<vector<int> >m, int r, int c) 
    {
        vector<int>v;
        int re = r-1;
        int ce = c-1;
        int rs = 0, cs = 0;
        
        while(cs<=ce && rs<=re){
            
            for(int k=cs;k<=ce;k++)
                v.push_back(m[rs][k]);
            rs++;
            
            for(int k=rs;k<=re;k++)
                v.push_back(m[k][ce]);
            ce--;
            
            if(rs<=re){
                for(int k=ce;k>=cs;k--)
                    v.push_back(m[re][k]);
                re--;
            }
            if(cs<=ce){
                for(int k=re;k>=rs;k--)
                    v.push_back(m[k][cs]);
                cs++;
            }
        }
        return v;
    }
};
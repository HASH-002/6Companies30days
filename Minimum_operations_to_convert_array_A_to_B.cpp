class Solution {
  public:
    int minInsAndDel(int arr[], int b[], int n, int m) {
        vector<int>a;
        for(int i=0;i<n;i++){
            auto val = lower_bound(b,b+m,arr[i]);
            if(val!=b+m && *val==arr[i])
                a.push_back(arr[i]);
        }
        if(a.size()==0)
            return n+m;
            
        vector<int>v;
        v.push_back(a[0]);
        for(int i=1;i<a.size();i++){
            if(v.back()<a[i])
                v.push_back(a[i]);
            else{
                auto l = lower_bound(v.begin(),v.end(),a[i]);
                *l = a[i];
            }
        }
        return n+m-2*v.size();
    }
};
class Solution{
    public:
    vector<int> leaders(int a[], int n){
        vector<int>v; 
        v.push_back(a[n-1]);
        int mx = a[n-1];
        for(int i=n-2;i>=0;i--){
            if(mx<=a[i]){
                v.push_back(a[i]);
                mx = a[i];
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
class Solution{
    public:
    vector<vector<int>> fourSum(vector<int> &a, int k) {
        vector<vector<int>>v;
        int n = a.size();
        sort(a.begin(),a.end());
        for(int i=0;i<n-3;i++){
            if(i!=0 && a[i]==a[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j!=i+1 && a[j]==a[j-1]) continue;
                int l = j+1;
                int h = n-1;
                int sum = k-a[i]-a[j];
                while(l<h){
                    if(a[l]+a[h]==sum){
                        v.push_back({a[i],a[j],a[l],a[h]});
                        while(l<n && a[l]==a[l+1]) l++;
                        while(h>0 && a[h]==a[h-1]) h--;
                        l++;
                        h--;
                    }else if(a[l]+a[h]>=sum)
                        h--;
                    else
                        l++;
                }
            }  
        }
        return v;
    }
};
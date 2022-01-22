class Solution {
public:
    bool solve(vector<int>& a, int m, int mid){
        int sum=0,cnt=1,n=a.size();
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum>mid){
                sum=a[i];
                cnt++;
                if(cnt>m)
                    return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& a, int m) {
        int n=a.size(),h=0,l=a[0];
        for(int i=0;i<n;i++){
            h+=a[i];
            l=max(l,a[i]);
        }
        int ans;
        while(l<=h){
            int mid = (h-l)/2+l;
            if(solve(a,m,mid)){
                ans = mid;
                h = mid-1;
            }else
                l = mid+1;
        }
        return ans;
    }
};
class Solution {
public:
    int longestMountain(vector<int>& a) {
        if(a.size()<3)
            return 0;
        
        int up=0, down=0, n=a.size(), len=0;
        for(int i=1;i<n;i++){
            if((down && a[i]>a[i-1]) || a[i]==a[i-1]) up=down=0;
            up += a[i]>a[i-1];
            down += a[i]<a[i-1];
            if(up && down)
            len = max(len,up+down+1);
        }
        return len;
    }
};
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> a, int n, int k) {
        vector<int>ans;
        deque<int>d;
        int i=0,j=0;
        while(j<n){
            if(j>=k)
                if(a[i++]==d.front())
                    d.pop_front();
            
            while(!d.empty() && a[j]>d.back())
                d.pop_back();
            d.push_back(a[j]);
            
            if(j>=k-1)
                ans.push_back(d.front());
            j++;
        }
        return ans;
    }
};
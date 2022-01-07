class Solution
{
  public:
    vector <int> max_of_subarrays(int *a, int n, int k)
    {
        vector<int>res;
        deque<int>d;
        int i=0,j=0;
        while(j<n){
            if(j>=k){
                if(!d.empty() && i==d.front())
                    d.pop_front();
                i++;
            }
            while(!d.empty() && a[j]>= a[d.back()])
                d.pop_back();
            d.push_back(j);
            
            if(j>=k-1)
                res.push_back(a[d.front()]);
            j++;
        }
        return res;
    }
};
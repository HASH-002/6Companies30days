class Solution
{
    public:
    vector<int> subarraySum(int a[], int n, long long s)
    {
        vector<int>v;
        long long sum=0;
        int i=0,j=0,k=0,l=0;
        while(j<n){
            sum+=a[j];
            while(i!=j && sum>s){
                sum -= a[i];
                i++;
            }
            if(sum==s){
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            j++;
        }
        v.push_back(-1);
        return v;
    }
};
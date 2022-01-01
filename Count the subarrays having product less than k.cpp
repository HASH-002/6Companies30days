class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int i=0,j=0,count = 0;
        long long num=1;
        while(j<a.size()){
            num *= a[j];
            while(i<=j && num>=k)
                num /= a[i++];
            
            count += j-i+1;
            j++;
        }
        return count;
    }
};
class Solution
{
    public:
    int FindMaxSum(int a[], int n)
    {
        int inc=a[0],exc=0;
        for(int i=1;i<n;i++){
            int temp = exc+a[i];
            exc = max(inc,exc);
            inc = temp;
        }
        return max(inc,exc);
    }
};
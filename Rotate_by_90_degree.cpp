void rotate(vector<vector<int>>&a)
{
    int n = a.size();
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            swap(a[i][j],a[j][i]);
    
    for(int j=0;j<n;j++)
        for(int i=0;i<n/2;i++)
            swap(a[i][j],a[n-i-1][j]);
}
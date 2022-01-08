class Solution{
public:
    int isValid(vector<vector<int>> a){
        int r[9][9]={0}, c[9][9]={0}, b[9][9]={0};
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                if(a[i][j]){
                    if(r[i][a[i][j]-1] || c[j][a[i][j]-1] || b[i/3*3+j/3][a[i][j]-1])
                        return false;
                    r[i][a[i][j]-1]++;
                    c[j][a[i][j]-1]++;
                    b[i/3*3+j/3][a[i][j]-1]++;
                }
            }
        return true;
    }
}
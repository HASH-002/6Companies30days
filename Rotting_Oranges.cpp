class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int count=0, n=a.size(),m=a[0].size(), fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(a[i][j]==2)
                    q.push({i,j});
                else if(a[i][j]==1)
                    fresh++;
            }
        
        while(!q.empty()){
            int size = q.size();
            bool flag = false;
            for(int k=0; k<size; k++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(i+1<n && a[i+1][j]==1){
                    a[i+1][j] = 2;
                    q.push({i+1,j});
                    fresh--;
                }
                if(i-1>=0 && a[i-1][j]==1){
                    a[i-1][j] = 2;
                    q.push({i-1,j});
                    fresh--;
                }
                if(j+1<m && a[i][j+1]==1){
                    a[i][j+1] = 2;
                    q.push({i,j+1});
                    fresh--;
                }
                if(j-1>=0 && a[i][j-1]==1){
                    a[i][j-1] = 2;
                    q.push({i,j-1});
                    fresh--;
                }
            }
            count++;
        }
        
        if(fresh) return -1;
        return count==0 ? count : count-1;
    }
};
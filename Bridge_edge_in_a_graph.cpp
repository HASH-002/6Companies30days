class Solution
{
	public:
    void dfs(vector<int> a[], bool visited[],int s){
        visited[s]=true;
        for(int i=0;i<a[s].size();i++)
            if(visited[a[s][i]]==false)
                dfs(a,visited,a[s][i]);
            
    }
    // A good solution is to check whether you can visit vertex c after removeing the given edge
    int isBridge(int n, vector<int> a[], int c, int d) 
    {
        bool visited[n]={0};
        a[c].erase(find(a[c].begin(),a[c].end(),d));
        a[d].erase(find(a[d].begin(),a[d].end(),c));
        dfs(a,visited,d);
        return !visited[c];
    }
};
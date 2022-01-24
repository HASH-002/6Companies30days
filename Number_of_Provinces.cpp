class Solution {
   public:
    void dfs(vector<vector<int>>& a, bool visited[], int s) {
        visited[s] = true;
        for (int i = 0; i < a[s].size(); i++)
            if (!visited[i] && a[s][i] == 1)
                dfs(a, visited, i);
    }
    int findCircleNum(vector<vector<int>>& a) {
        bool visited[a.size()];
        memset(visited, 0, sizeof visited);
        int ans = 0;
        for (int i = 0; i < a.size(); i++)
            if (!visited[i]) {
                ans++;
                dfs(a, visited, i);
            }
        return ans;
    }
};
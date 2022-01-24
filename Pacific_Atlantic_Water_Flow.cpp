class Solution {
   public:
    void solve(vector<vector<int>>& a, vector<vector<bool>>& ocean, int i, int j, int d) {
        if (j < 0 || i < 0 || j >= a[0].size() || i >= a.size() || a[i][j] < d || ocean[i][j])
            return;
        ocean[i][j] = true;
        solve(a, ocean, i, j + 1, a[i][j]);
        solve(a, ocean, i + 1, j, a[i][j]);
        solve(a, ocean, i, j - 1, a[i][j]);
        solve(a, ocean, i - 1, j, a[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        vector<vector<int>> v;
        vector<vector<bool>> p(a.size(), vector<bool>(a[0].size(), false));
        vector<vector<bool>> m(a.size(), vector<bool>(a[0].size(), false));

        // dfs from edges to the maximum points it can reach
        for (int i = 0; i < a.size(); i++) {
            solve(a, p, i, 0, INT_MIN);
            solve(a, m, i, a[0].size() - 1, INT_MIN);
        }
        for (int i = 0; i < a[0].size(); i++) {
            solve(a, p, 0, i, INT_MIN);
            solve(a, m, a.size() - 1, i, INT_MIN);
        }

        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < a[0].size(); j++)
                if (m[i][j] && p[i][j])
                    v.push_back({i, j});
        return v;
    }
};
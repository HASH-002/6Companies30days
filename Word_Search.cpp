class Solution {
   public:
    bool solve(vector<vector<char>>& a, string& s, int i, int j, int k) {
        if (k == s.length())
            return true;
        if (i >= a.size() || j >= a[0].size() || i < 0 || j < 0 || s[k] != a[i][j])
            return false;

        a[i][j] = '0';
        bool ans = solve(a, s, i + 1, j, k + 1) || solve(a, s, i, j + 1, k + 1) || solve(a, s, i - 1, j, k + 1) || solve(a, s, i, j - 1, k + 1);
        a[i][j] = s[k];
        return ans;
    }
    bool isWordExist(vector<vector<char>>& a, string s) {
        int n = a.size();
        int m = a[0].size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (solve(a, s, i, j, 0))
                    return true;
            }
        return false;
    }
};
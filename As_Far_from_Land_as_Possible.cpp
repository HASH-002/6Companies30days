class Solution {
   public:
    int maxDistance(vector<vector<int>>& a) {
        queue<pair<int, int>> q;
        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < a[0].size(); j++)
                if (a[i][j] == 1) {
                    q.push({i + 1, j});
                    q.push({i, j + 1});
                    q.push({i - 1, j});
                    q.push({i, j - 1});
                }

        if (q.size() == a.size() * a[0].size())
            return -1;

        int ans = 0;
        while (!q.empty()) {
            ans++;
            int n = q.size();
            while (n--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if (i >= 0 && j < a[0].size() && j >= 0 && i < a.size() && a[i][j] == 0) {
                    a[i][j] = ans;
                    q.push({i + 1, j});
                    q.push({i, j + 1});
                    q.push({i - 1, j});
                    q.push({i, j - 1});
                }
            }
        }
        return ans == 1 ? -1 : ans - 1;
    }
};
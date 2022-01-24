class Solution {
   public:
    vector<int> findOrder(int n, vector<vector<int>>& a) {
        int in[n];
        memset(in, 0, sizeof in);
        vector<vector<int>> g(n);
        for (int i = 0; i < a.size(); i++) {
            g[a[i][1]].push_back(a[i][0]);
            in[a[i][0]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (in[i] == 0)
                q.push(i);

        vector<int> v;
        while (!q.empty()) {
            int p = q.front();
            v.push_back(p);
            q.pop();
            for (int i = 0; i < g[p].size(); i++) {
                in[g[p][i]]--;
                if (in[g[p][i]] == 0)
                    q.push(g[p][i]);
            }
        }

        for (int i = 0; i < n; i++)
            if (in[i] != 0)
                return {};

        return v;
    }
};
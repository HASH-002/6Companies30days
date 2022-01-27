class Solution {
   public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& s, int start, int end) {
        vector<pair<int, double>> a[n];
        for (int i = 0; i < e.size(); i++) {
            a[e[i][0]].push_back({e[i][1], s[i]});
            a[e[i][1]].push_back({e[i][0], s[i]});
        }

        bool visited[n];
        double prob[n];
        for (int i = 0; i < n; i++) {
            visited[i] = false;
            prob[i] = 0;
        }

        prob[start] = 1;
        priority_queue<pair<double, int>> q;
        q.push({1, start});
        while (!q.empty()) {
            int n = q.top().second;
            double p = q.top().first;
            q.pop();
            if (!visited[n]) {
                visited[n] = true;
                for (int i = 0; i < a[n].size(); i++) {
                    int next = a[n][i].first;
                    double nextprob = a[n][i].second;
                    if (prob[next] < p * nextprob) {
                        prob[next] = p * nextprob;
                        q.push({prob[next], next});
                    }
                }
            }
        }
        return prob[end];
    }
};
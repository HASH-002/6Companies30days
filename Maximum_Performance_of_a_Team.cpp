class Solution {
   public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({e[i], s[i]});

        sort(v.begin(), v.end(), greater<pair<int, int>>());

        long res = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; i++) {
            q.push(v[i].second);
            sum += v[i].second;
            if (q.size() > k) {
                sum -= q.top();
                q.pop();
            }
            res = max(res, sum * v[i].first);
        }
        return res % (long)(1e9 + 7);
    }
};
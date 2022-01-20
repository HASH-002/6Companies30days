typedef pair<int, pair<int, int>> ppi;
class Solution {
   public:
    pair<int, int> findSmallestRange(int a[][N], int n, int k) {
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        int mx = a[0][0];
        for (int i = 0; i < k; i++) {
            mx = max(mx, a[i][0]);
            pq.push({a[i][0], {i, 0}});
        }
        int mn = pq.top().first;
        int ans = mx - pq.top().first;
        int maxi = mx;
        while (true) {
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if (j + 1 < n) {
                pq.push({a[i][j + 1], {i, j + 1}});
                maxi = max(maxi, a[i][j + 1]);
                int r = maxi - pq.top().first;
                if (r < ans) {
                    mn = pq.top().first;
                    mx = maxi;
                    ans = r;
                }
            } else
                break;
        }
        return {mn, mx};
    }
};
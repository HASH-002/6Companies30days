class Solution {
   public:
    int numberOfBoomerangs(vector<vector<int>>& a) {
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            unordered_map<long, int> m(a.size());
            for (int j = 0; j < a.size(); j++) {
                if (i == j)
                    continue;
                int dx = a[i][0] - a[j][0];
                int dy = a[i][1] - a[j][1];
                long d = dx * dx + dy * dy;
                m[d]++;
            }
            for (auto i : m) {
                if (i.second > 1)
                    res += i.second * (i.second - 1);
            }
        }
        return res;
    }
};
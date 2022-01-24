class Solution {
   public:
    bool solve(vector<int>& a, int d, int mid) {
        int k = 0;
        for (int i = 0; i < a.size(); i++) {
            k += ceil((double)a[i] * 1.0 / (double)mid);
            if (k > d)
                return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& a, int d) {
        int l = 1;
        int h = *max_element(a.begin(), a.end());
        int ans = 0;
        while (l <= h) {
            int mid = (h - l) / 2 + l;
            if (solve(a, d, mid)) {
                ans = mid;
                h = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};
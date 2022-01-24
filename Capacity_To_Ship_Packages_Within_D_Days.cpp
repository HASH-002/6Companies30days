class Solution {
   public:
    bool solve(vector<int>& a, int d, int mid) {
        int sum = 0, k = 1;
        for (int i = 0; i < a.size(); i++) {
            sum += a[i];
            if (sum > mid) {
                sum = a[i];
                k++;
                if (k > d)
                    return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& a, int d) {
        int l = *max_element(a.begin(), a.end());
        int h = accumulate(a.begin(), a.end(), 0);
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
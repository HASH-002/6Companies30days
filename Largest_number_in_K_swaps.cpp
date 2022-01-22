class Solution {
   public:
    void solve(string s, int k, int i, string& ans) {
        if (k == 0)
            return;

        char maxi = s[i];
        for (int j = i + 1; j < s.length(); j++)
            maxi = max(s[j], maxi);

        if (maxi != s[i])
            k--;

        for (int j = s.length() - 1; j >= i; j--) {
            if (s[j] == maxi) {
                swap(s[i], s[j]);
                if (ans < s)
                    ans = s;
                solve(s, k, i + 1, ans);
                swap(s[i], s[j]);
            }
        }
    }
    string findMaximumNum(string s, int k) {
        string ans = s;
        solve(s, k, 0, ans);
        return ans;
    }
};
class Solution {
   public:
    vector<int> find3Numbers(vector<int> a, int n) {
        int mn[n], mx[n];

        mn[0] = a[0];
        for (int i = 1; i < n; i++)
            mn[i] = min(a[i], mn[i - 1]);

        mx[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
            mx[i] = max(a[i], mx[i + 1]);

        for (int i = 1; i < n - 1; i++)
            if (a[i] != mn[i] && a[i] != mx[i])
                return {mn[i], a[i], mx[i]};

        return {};
    }
};
class Solution {
   public:
    int minSwaps(vector<vector<int>>& a) {
        int n = a.size();
        int maxright[n];
        memset(maxright, 0, sizeof maxright);

        for (int i = 0; i < n; i++) {
            int j = n - 1;
            while (j >= 0 && a[i][j] == 0)
                j--;
            maxright[i] = n - j - 1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (maxright[i] < n - i - 1) {
                int j = i + 1;
                while (j < n) {
                    ans++;
                    swap(maxright[i], maxright[j]);
                    if (maxright[i] >= n - i - 1)
                        break;
                    j++;
                }
                if (j == n)
                    return -1;
            }
        }
        return ans;
    }
};
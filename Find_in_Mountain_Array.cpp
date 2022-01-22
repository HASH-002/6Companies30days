class Solution {
   public:
    int findInMountainArray(int t, MountainArray &a) {
        int l = 0, h = a.length() - 1, peak;
        while (l < h) {
            int mid = (h - l) / 2 + l;
            if (a.get(mid) < a.get(mid + 1))
                l = peak = mid + 1;
            else
                h = mid;
        }
        l = 0, h = peak;
        while (l <= h) {
            int mid = (h - l) / 2 + l;
            if (a.get(mid) == t)
                return mid;
            else if (a.get(mid) > t)
                h = mid - 1;
            else
                l = mid + 1;
        }
        l = peak + 1, h = a.length() - 1;
        while (l <= h) {
            int mid = (h - l) / 2 + l;
            if (a.get(mid) == t)
                return mid;
            else if (a.get(mid) < t)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};
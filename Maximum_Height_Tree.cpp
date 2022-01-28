class Solution {
   public:
    int height(int n) {
        double root = sqrt(1 + 8 * n * 1.0);
        return (root - 1) / 2;
    }
};
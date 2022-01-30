class Solution {
   public:
    int divide(int A, int B) {
        // for the corner case, If A is INT_MIN, and B is -1,
        // the result will be 1 + INT_MAX, hence overflowing
        // 32 bits, handle it first
        if (A == INT_MIN && B == -1)
            return INT_MAX;

        long a = abs(A), b = abs(B), res = 0;
        while (a - b >= 0)  // can we take 'b' from 'a' atleast once?
        {
            int x = 0;                      // 2^0 = 1
            while (a - (b << 1 << x) >= 0)  // b*2, b*2*2, b*2*2*2, ...
                x++;

            res += 1 << x;  // adding count of b = 1,2,4..
            a -= b << x;
        }
        return (A > 0) == (B > 0) ? res : -res;
    }
};
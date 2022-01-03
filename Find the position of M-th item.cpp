class Solution {
  public:
    int findPosition(int n , int m , int k) {
        int res = (m+k-1)%n;
        return res==0 ? n : res; 
    }
};
class Solution {
  public:
    int countBitsFlip(int a, int b) {
        int diff=a^b;
        return __builtin_popcount(diff);
    }
};
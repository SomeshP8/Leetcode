class Solution {
public:
    int countSetBits(int n) {
        long long ans = 0;
        for (long long bit = 1; bit <= n; bit <<= 1) {
            long long blockSize = bit << 1;
            long long fullBlocks = (n + 1) / blockSize;
            ans += fullBlocks * bit;
            long long remainder = (n + 1) % blockSize;
            ans += max(0LL, remainder - bit);
        }
        return ans;
    }
};
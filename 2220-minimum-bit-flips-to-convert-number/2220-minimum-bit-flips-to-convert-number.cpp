class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff = start ^ goal;
        int cnt = 0;
        while (diff) {
            diff = diff & (diff - 1);
            cnt++;
        }
        return cnt;
    }
};
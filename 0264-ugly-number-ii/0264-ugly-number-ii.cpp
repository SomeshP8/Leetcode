class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        for (int i = 1; i <= n; i++) {
            int aa = dp[i2] * 2;
            int bb = dp[i3] * 3;
            int cc = dp[i5] * 5;
            int mini = min({aa, bb, cc});
            dp[i] = mini;
            if (mini == aa) {
                i2++;
            }
            if (mini == bb) {
                i3++;
            }
            if (mini == cc) {
                i5++;
            }
        }
        return dp[n - 1];
    }
};
class Solution {
public:
    string s;
    pair<long long, long long> dp[12][11][11][2][2];
    bool vis[12][11][11][2][2];

    pair<long long, long long> dfs(int pos, int prev1, int prev2, bool tight, bool started) {
        if (pos == s.size()) {
            return {1, 0}; 
        }

        if (vis[pos][prev1][prev2][tight][started])
            return dp[pos][prev1][prev2][tight][started];

        long long totalCount = 0, totalWave = 0;

        int limit = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == limit);
            bool newStarted = started || (d != 0);

            int nprev1 = prev1, nprev2 = prev2;

            long long add = 0;

            if (!newStarted) {
                nprev1 = nprev2 = 10; 
            } else {
                if (started) {
                    nprev2 = prev1;
                    nprev1 = d;

                    if (prev2 != 10) {
                        if ((prev1 > prev2 && prev1 > d) ||
                            (prev1 < prev2 && prev1 < d)) {
                            add = 1;
                        }
                    }
                } else {
                    nprev1 = d;
                    nprev2 = 10;
                }
            }

            auto [cnt, wave] = dfs(pos + 1, nprev1, nprev2, newTight, newStarted);

            totalCount += cnt;
            totalWave += wave + cnt * add;
        }

        vis[pos][prev1][prev2][tight][started] = true;
        return dp[pos][prev1][prev2][tight][started] = {totalCount, totalWave};
    }

    long long solve(long long x) {
        if (x < 0) return 0;
        s = to_string(x);
        memset(vis, false, sizeof(vis));
        return dfs(0, 10, 10, 1, 0).second;
    }

    int totalWaviness(int num1, int num2) {
        return solve(num2) - solve(num1 - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
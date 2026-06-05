class Solution {
public:
    typedef long long ll;

    struct Node {
        ll ways, sum;
    };

    Node dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];
    string s;

    Node solve(int pos, int prev1, int prev2, bool tight, bool started) {
        if (pos == s.size()) return {1, 0};

        if (vis[pos][prev1][prev2][tight][started])
            return dp[pos][prev1][prev2][tight][started];

        vis[pos][prev1][prev2][tight][started] = true;

        ll ways = 0, sum = 0;
        int limit = tight ? (s[pos] - '0') : 9;

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == limit);
            bool newStarted = started || (d != 0);

            if (!newStarted) {
                Node nxt = solve(pos + 1, 10, 10, newTight, false);
                ways += nxt.ways;
                sum += nxt.sum;
                continue;
            }

            if (!started) {
                Node nxt = solve(pos + 1, d, 10, newTight, true);
                ways += nxt.ways;
                sum += nxt.sum;
            } 
            else if (prev2 == 10) {
                Node nxt = solve(pos + 1, d, prev1, newTight, true);
                ways += nxt.ways;
                sum += nxt.sum;
            } 
            else {
                int add = ((prev1 > prev2 && prev1 > d) ||
                           (prev1 < prev2 && prev1 < d)) ? 1 : 0;

                Node nxt = solve(pos + 1, d, prev1, newTight, true);

                ways += nxt.ways;
                sum += nxt.sum + add * nxt.ways;
            }
        }

        return dp[pos][prev1][prev2][tight][started] = {ways, sum};
    }

    ll f(ll x) {
        if (x <= 0) return 0;
        s = to_string(x);
        memset(vis, 0, sizeof(vis));
        return solve(0, 10, 10, true, false).sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        return f(num2) - f(num1 - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        if (freq.count(1)) {
            if (freq[1] % 2)
                ans = max(ans, freq[1]);
            else
                ans = max(ans, freq[1] - 1);
        }

        vector<long long> vals;
        for (auto& p : freq) {
            if (p.first != 1)
                vals.push_back(p.first);
        }

        sort(vals.begin(), vals.end(), greater<long long>());

        unordered_map<long long, int> dp;

        for (long long x : vals) {
            dp[x] = 1;

            if (freq[x] >= 2) {
                long long sq = x * x;

                if (sq <= 1000000000LL && dp.count(sq)) {
                    dp[x] = dp[sq] + 2;
                }
            }

            ans = max(ans, dp[x]);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
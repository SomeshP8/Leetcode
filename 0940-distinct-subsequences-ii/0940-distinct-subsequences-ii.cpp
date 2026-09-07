class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;
        
        long long dp = 1;
        vector<long long> last(26, 0);
        
        for (char c : s) {
            int index = c - 'a';
            
            long long oldDp = dp;
            
            dp = (2 * dp - last[index] + MOD) % MOD;
            
            last[index] = oldDp;
        }
        
        return (dp - 1 + MOD) % MOD;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
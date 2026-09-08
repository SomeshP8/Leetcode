class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
         int ans = 0;
        for (auto x : nums) {
            for (auto y : nums) {
                if (abs(x - y) <= min(x, y)) {
                    ans = max(ans, x ^ y);
                }
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
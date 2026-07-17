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

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
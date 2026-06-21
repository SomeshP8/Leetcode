class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi = 0;
        for (int cost : costs) {
            if (cost > maxi) {
                maxi = cost;
            }
        }
        vector<int> count(maxi + 1, 0);
        for (int cost : costs) {
            count[cost]++;
        }
        int bars = 0;
        int rc = coins;
        for (int cost = 1; cost <= maxi; ++cost) {
            if (count[cost] > 0) {
                int cb = min(count[cost], rc / cost);
                bars += cb;
                rc -= cb * cost;
                if (cb == 0) break;
            }
        }
        
        return bars;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
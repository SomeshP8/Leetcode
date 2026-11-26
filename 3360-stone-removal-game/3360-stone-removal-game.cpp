
class Solution {
public:
    bool canAliceWin(int n) {
        return (n >= 10 && n < 19) || (n >= 27 && n < 34) || (n >= 40 && n < 45) || (n >= 49 && n <= 50);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
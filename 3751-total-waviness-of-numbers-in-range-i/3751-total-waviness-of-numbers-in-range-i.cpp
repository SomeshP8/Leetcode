class Solution {
public:
    int waviness(int x) {
        string s = to_string(x);
        int cnt = 0;
        for(int i = 1; i < (int)s.size() - 1; i++) {
            if ((s[i] > s[i - 1] && s[i] > s[i + 1]) ||
                (s[i] < s[i - 1] && s[i] < s[i + 1])) {
                cnt++;
            }
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        long long ans = 0;
        for (int x = num1; x <= num2; x++) {
            ans += waviness(x);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
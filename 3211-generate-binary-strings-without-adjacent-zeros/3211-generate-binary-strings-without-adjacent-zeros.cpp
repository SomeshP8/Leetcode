class Solution {
public:
    vector<string> result;
    void solve(int n, string curr) {
        if (curr.size() == n) {
            result.push_back(curr);
            return;
        }
        solve(n, curr + '1');
        if (curr.empty() || curr.back() != '0') {
            solve(n, curr + '0');
        }
    }
    
    vector<string> validStrings(int n) {
        solve(n, "");
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
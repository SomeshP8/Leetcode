class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, bool> mp;
        for (auto it : nums) {
            if (it % k == 0) {
                mp[it / k] = true;
            }
        }
        int i = 1;
        while (true) {
            if (!mp[i]) {
                return i * k;
            }
            i++;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
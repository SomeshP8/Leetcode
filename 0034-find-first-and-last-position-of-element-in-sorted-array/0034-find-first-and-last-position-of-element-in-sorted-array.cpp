class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end() || *it != target) {
            return {-1, -1};
        }
        auto it1 = upper_bound(nums.begin(), nums.end(), target);
        return {static_cast<int>(it - nums.begin()), static_cast<int>(it1 - nums.begin() - 1)};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
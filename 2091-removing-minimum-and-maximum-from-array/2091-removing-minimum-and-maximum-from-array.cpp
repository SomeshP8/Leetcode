class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int i = distance(nums.begin(), min_element(nums.begin(), nums.end()));
        int j = distance(nums.begin(), max_element(nums.begin(), nums.end()));
        
        if (i > j) swap(i, j);
        
        return min({j + 1, n - i, i + 1 + n - j});
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
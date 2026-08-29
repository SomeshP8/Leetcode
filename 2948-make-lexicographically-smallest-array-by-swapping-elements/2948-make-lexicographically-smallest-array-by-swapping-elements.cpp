class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> sorted_pairs(n);
        for (int i = 0; i < n; ++i) {
            sorted_pairs[i] = {nums[i], i};
        }
        sort(sorted_pairs.begin(), sorted_pairs.end());
        vector<int> result(n);
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && sorted_pairs[j].first - sorted_pairs[j - 1].first <= limit) {
                j++;
            }
            vector<int> indices;
            for (int k = i; k < j; ++k) {
                indices.push_back(sorted_pairs[k].second);
            }
            sort(indices.begin(), indices.end());
            for (int k = 0; k < indices.size(); ++k) {
                result[indices[k]] = sorted_pairs[i + k].first;
            }
            i = j;
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
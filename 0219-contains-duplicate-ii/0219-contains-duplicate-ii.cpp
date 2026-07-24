#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                set.erase(nums[i - k - 1]);
            }
            if (set.count(nums[i])) {
                return true;
            }
            set.insert(nums[i]);
        }
        
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> freq;
        
        int prefix = 0;
        int result = 0;
        
        freq[0] = 1;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                prefix += 1;
            else
                prefix -= 1;
            
            for (auto &it : freq) {
                if (it.first < prefix)
                    result += it.second;
            }
            
            freq[prefix]++;
        }
        
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
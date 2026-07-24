class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        bool somesh = false;
        unordered_map<int, int> seen;
        for(int i = 0; i < n; i++){
            if(seen.count(nums[i]) && abs(i - seen[nums[i]]) <= k){
                somesh = true;
                break; 
            }
            seen[nums[i]] = i;
        }
        
        if(somesh) return true;
        else return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
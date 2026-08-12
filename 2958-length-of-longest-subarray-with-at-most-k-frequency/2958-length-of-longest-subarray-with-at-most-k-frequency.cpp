class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
       int n=nums.size();
       unordered_map<int,int>mp;
       int left=0;
       int maxi=0;
       for(int right=0;right<n;right++){
        mp[nums[right]]++;
        while(mp[nums[right]]>k){
            mp[nums[left]]--;
            left++;
        }
        maxi=max(maxi,(right-left)+1);
       }
       return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
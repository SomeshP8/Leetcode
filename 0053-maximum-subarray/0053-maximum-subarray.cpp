class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int n=nums.size();
       int curr=0,maxi=nums[0];
       for(int num:nums){
        curr+=num;
        if(curr>maxi) maxi=curr;
        if(curr<0) curr=0;
       }
    return maxi;;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
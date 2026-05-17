class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        for(int x:nums){
            if(x!=0) temp.push_back(x);
        }
        int zeroes=n-temp.size();
        while(zeroes--) temp.push_back(0);
        nums=temp;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna
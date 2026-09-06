class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jumps=0,l=0,r=0;
        while(r<n-1){
            int far=0;
            for(int i=l;i<=r;i++){
                far=max(far,i+nums[i]);
            }
            jumps++;
            l=r+1;
            r=far;  
        }
        return jumps;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
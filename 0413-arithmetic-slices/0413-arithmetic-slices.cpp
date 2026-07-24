class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)return 0;
        int dif=nums[1]-nums[0];
        int ans=0,l=0;
        for(int r=1;r<n;r++){
            int cd=nums[r]-nums[r-1];
            if(cd==dif && r-l+1>=3){
                ans+=(r-l+1-2);
            }else{
                l=r-1;
                dif=nums[r]-nums[l];
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
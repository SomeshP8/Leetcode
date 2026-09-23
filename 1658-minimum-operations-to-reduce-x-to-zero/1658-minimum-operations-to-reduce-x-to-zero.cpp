class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int total=0;
        for(int num:nums)
              total+=num;
            int target=total-x;
            if(target<0) return -1;
            if(target==0) return n;
            int left=0,sum=0,maxi=-1;
            for(int right=0;right<n;right++){
                sum+=nums[right];
                while(sum>target){
                    sum-=nums[left];
                    left++;
                }
                if(sum==target){
                    maxi=max(maxi,right-left+1);
                }
            }
            if(maxi==-1) return -1;
            return n-maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
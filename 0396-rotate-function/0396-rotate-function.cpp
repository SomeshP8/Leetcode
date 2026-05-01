class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum=0,f0=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            f0+=i*nums[i];
        }
        int mx=f0;
        int curr=f0;
        for(int k=1;k<n;k++){
            curr=curr+sum-n*nums[n-k];
            mx=max(mx,curr);
        }
        return mx;
    }
};
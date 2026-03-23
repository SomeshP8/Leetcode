class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum=1;
        int n=nums.size();
        vector<int>som(n,1);
        for(int i=1;i<n;i++){
             som[i]=som[i-1]*nums[i-1];
        }
        int right=1;
        for(int i=n-1;i>=0;i--){
            som[i]*=right;
            right*=nums[i];
        }
        return som;
    }
};
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=0;
        for(int x:nums) total+=x;
        if((target+total)%2!=0 || abs(target)>total) return 0;
        int sumP=(target+total)/2;
        vector<int>dp(sumP+1,0);
        dp[0]=1;
        for(int num:nums){
            for(int j=sumP;j>=num;j--){
                dp[j]+=dp[j-num];
            }
        }
        return dp[sumP];
    }
};
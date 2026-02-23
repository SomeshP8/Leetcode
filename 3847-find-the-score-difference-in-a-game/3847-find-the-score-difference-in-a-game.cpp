class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int ans=0,x=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1) x*=-1;
            if((i+1)%6==0) x*=-1;
            ans+=x*nums[i];
        }
        return ans;
    }
};
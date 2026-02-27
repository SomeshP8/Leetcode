class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int bit=0;bit<=31;bit++){
            int c=0;
            for(int i=0;i<n;i++){
                if(nums[i] & (1<<bit)){
                    c++;
                }
            }
                if(c%3==1){
                    ans=ans|(1<<bit);
                }
            }
            return ans;
    }
};
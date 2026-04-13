class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n=nums.size();
        int c=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                c=min(c,abs(i-start));
            }
        }
        return c;
    }
};
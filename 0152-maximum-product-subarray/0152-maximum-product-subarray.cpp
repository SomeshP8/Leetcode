class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pmax=nums[0],pmin=nums[0],res=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            int cmax=max({nums[i],nums[i]*pmax,nums[i]*pmin});
            int cmin=min({nums[i],nums[i]*pmax,nums[i]*pmin});
            pmax=cmax;
            pmin=cmin;
            res=max(res,cmax);
        }
        return res;
    }
};
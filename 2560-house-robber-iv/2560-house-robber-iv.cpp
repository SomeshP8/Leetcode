class Solution {
public: 
    bool rob(vector<int>& nums,int k,int can){
        int c=0;
        for(int i=0;i<nums.size();i++){
        if(nums[i]<=can){
          c++;
          i++;
        }
        if(c>=k) return true;
        }
      return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(rob(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else
              low=mid+1;
        }
        return low;
    }
};
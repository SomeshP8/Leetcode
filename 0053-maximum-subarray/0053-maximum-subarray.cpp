class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int n=nums.size();
       int start,anss,anse;
       int sum=0,maxi=INT_MIN;
       for(int i=0;i<n;i++){
        if(sum==0) start=i;
        sum+=nums[i];
        if(sum>maxi){
        maxi=sum;
        anss=start,anse=i;
        }
        if(sum<0) sum=0;
    }
    return maxi;
    }
};
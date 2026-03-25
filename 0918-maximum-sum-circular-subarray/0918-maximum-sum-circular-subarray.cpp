class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        long long n=nums.size();
        long long maxi=INT_MIN;
        for(int i=0;i<n;i++){
            long long cur=0;
            for(int j=0;j<n;j++){
                cur+=nums[(i+j)%n];
                maxi=max(maxi,cur);
            }
        }
        return maxi;
    }
};
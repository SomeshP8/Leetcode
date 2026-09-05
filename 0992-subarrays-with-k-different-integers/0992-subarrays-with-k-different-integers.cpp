class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return somesh(nums,k)-somesh(nums,k-1);
    }
private:
   int somesh(vector<int>&nums,int k){
    int l=0,r=0,cnt=0;
    map<int,int>mp;
    while(r<nums.size()){
        mp[nums[r]]++;
         while(mp.size()>k){
         mp[nums[l]]--;
          if(mp[nums[l]]==0){
            mp.erase(nums[l]);
          }
          l++;
       } 
       cnt+=(r-l+1);
       r++;
    }
    return cnt;
   }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
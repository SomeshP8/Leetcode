class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        int csum=0;
        int cnt=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            csum+=nums[i];
            if(mp.find(csum-k)!=mp.end()){
                cnt+=mp[csum-k];
            }
            mp[csum]++;
        }
        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
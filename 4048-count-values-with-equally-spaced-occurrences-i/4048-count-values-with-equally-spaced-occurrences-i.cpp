class Solution {
public:
     
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> mp(101);
        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);
        int cnt=0;
        for(int i=0;i<=100;i++){
            if(mp[i].size()==3){
                if(mp[i][1]-mp[i][0]==mp[i][2]-mp[i][1]) cnt++;
            }
        }
       // cout<<cnt;
        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
         int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);
        int cnt=0;
        for(auto& [val,idx]:mp){
            if(idx.size()<3) continue; 
           int diff = idx[1] - idx[0];
            bool valid = true;
            for (int j = 2; j < idx.size(); ++j) {
                if (idx[j] - idx[j - 1] != diff) {
                    valid = false;
                    break;
                }
            }
            if (valid) cnt++;
        }
        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>>mp;
        vector<vector<int>>res;
        for(int i=0;i<groupSizes.size();i++){
            int size=groupSizes[i];
            mp[size].push_back(i);
            
            if(mp[size].size()==size){
                res.push_back(mp[size]);
                mp[size].clear();
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
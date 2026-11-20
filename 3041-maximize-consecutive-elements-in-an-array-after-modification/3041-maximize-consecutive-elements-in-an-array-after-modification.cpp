class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>best;
        int ans=0;
        for(int x:nums){
            best[x+1]=max(best[x+1],best[x]+1);
            best[x]=max(best[x],best[x-1]+1);
            ans=max(ans,best[x]);
            ans=max(ans,best[x+1]);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int prefix_sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                prefix_sum+=nums[i];
            }
            else {
                break;
            }
        }
        unordered_set<int>st(nums.begin(),nums.end());
        while(st.find(prefix_sum)!=st.end()){
            prefix_sum++;
        }
        return prefix_sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        set<int>st(nums.begin(),nums.end());
        int ls=0;
        for(int num:st){
            if(st.find(num-1)==st.end()){
                int cnum=num;
                int cs=1;
                while(st.find(cnum+1)!=st.end()){
                    cnum+=1;
                    cs+=1;
                }
                ls=max(ls,cs);
            }
        }
        return ls;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
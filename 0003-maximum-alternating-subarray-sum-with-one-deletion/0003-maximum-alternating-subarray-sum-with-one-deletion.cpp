class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
      const long long MIN_INF=-1e15;
        long long s00=MIN_INF;
        long long s01=MIN_INF;
        long long s10=MIN_INF;
        long long s11=MIN_INF;
        long long maxi=MIN_INF;
        for(int x:nums){
            long long next_s00=max((long long)x,s01+x);
            long long next_s01=s00-x;
            long long next_s10=max(s11+x,s00);
            long long next_s11=max(s10-x,s01);
            s00=next_s00;
            s01=next_s01;
            s10=next_s10;
            s11=next_s11;
            maxi=max({maxi,s00,s01,s10,s11});
        }
        return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
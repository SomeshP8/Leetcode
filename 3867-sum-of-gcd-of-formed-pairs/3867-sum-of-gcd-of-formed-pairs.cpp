class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref(n);
        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            pref[i]=__gcd(nums[i],mx);
        }
        sort(pref.begin(),pref.end());
        int l=0,r=n-1;
        long long sum=0;
        while(l<r){
            sum+=__gcd(pref[l],pref[r]);
            l++;
            r--;
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
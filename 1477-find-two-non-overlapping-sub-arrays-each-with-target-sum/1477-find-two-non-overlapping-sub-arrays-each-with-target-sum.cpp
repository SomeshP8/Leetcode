class Solution {
public:
     int minSumOfLengths(vector<int>& arr,int target) {
       long long n=arr.size();
        vector<int>dp(n,INT_MAX);
       long long l=0;
       long long sum=0;
       int len=0;long long ans=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            while(sum>target && l<=i){sum-=arr[l];l++;}
            if(sum==target) {
                 len=i-l+1;
                if(l>0 && dp[l-1]!=INT_MAX){
                     ans=min(ans,(long long)len+dp[l-1]);
                }
                dp[i]=min(dp[i],len);
            }
            if(i>0)dp[i]=min(dp[i-1],dp[i]);
            cout<<dp[i]<<" ";
        }
        return ans==INT_MAX?-1:ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
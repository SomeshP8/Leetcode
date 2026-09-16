class Solution {
public:
    const int M=1e9+7;
    int mod(int a){
        return (a%M + M)%M;
    }
    int add(int a,int b){
        return mod(mod(a)+mod(b));
    }
    int mul(int a,int b){
        return mod(mod(a)*mod(b));
    }
    int dp[1002][1002];
    int prefDp[1002][1002];
    int prefok(int n,int k){
        if(n<2) return 0;
        if(prefDp[n][k]!=-1) return prefDp[n][k];
        return prefDp[n][k]=add(prefok(n-1,k),ok(n,k));
    }
    int ok(int n,int k){
        if(k==1) return dp[n][k]=(n*(n-1))/2;
        if(n==1) return 0;
        if(n-1==k) return 1;
        if(n-1<k) return 0;
        if(dp[n][k]!=-1) return dp[n][k];
        int total=0;
        total=add(total,ok(n-1,k));
        total=add(total,prefok(n-1,k-1));
        return dp[n][k]=total;
    }
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        memset(prefDp,-1,sizeof(prefDp));
        return ok(n,k);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
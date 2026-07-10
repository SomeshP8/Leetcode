class Solution {
public:
    const int MOD = 1e9+7;
    int power(long long a,long long b){
        if(b==0){
            return 1;
        }
        long long half=power(a,b/2);
        long long res=(half*half)%MOD;
        if(b%2==1){
            res=(res*a)%MOD;
        }
        return res;
    }
    int countGoodNumbers(long long n){
        return (long long)power(5,(n+1)/2)*power(4,n/2)%MOD;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
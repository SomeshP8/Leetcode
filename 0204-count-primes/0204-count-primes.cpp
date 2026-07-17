class Solution {
public:
    int countPrimes(int n) {
     int c=0;
     vector<bool>prime(n+1,true);
     prime[0]=prime[1]=false;
     for(int i=2;i<n;i++){
        if(prime[i]){
            c++;
            for(int j=i*2;j<n;j+=i){
              prime[j]=0;  
            }
        }
     }
     return c;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
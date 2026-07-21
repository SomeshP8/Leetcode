class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones=0;
        int zeroes=0;
        vector<int>zero;
        for(char c:s){
            if(c=='1'){
                ones++;
                 if(zeroes>0){
                 zero.push_back(zeroes);
                 zeroes=0;
              }
            }
            else{
                zeroes++;
            }
          }
        if(zeroes>0){
            zero.push_back(zeroes);
        }
        int maxi=0;
        for(int i=1;i<zero.size();i++){
            maxi=max(maxi,zero[i-1]+zero[i]);
        }
        return ones+maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
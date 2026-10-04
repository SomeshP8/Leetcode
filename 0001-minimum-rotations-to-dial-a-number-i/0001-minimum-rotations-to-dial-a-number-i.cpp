class Solution {
public:
    int minRotations(string s) {
        int total=0,curr=0;
        for(char c:s){
            int t=c-'0';
            int diff=abs(t-curr);
            int mini=min(diff,10-diff);
            total+=mini;
            curr=t;
        }
        return total;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
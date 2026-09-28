class Solution {
public:
    int maxDepth(string s) {
        int curr=0,maxi=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(') {
              curr++;
               if(curr>maxi) maxi=curr;
            }
            else if(s[i]==')') curr-=1;
        }
        return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
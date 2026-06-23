class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for(int i=0;i<n.length();i++){
            ans=max(ans,(n[i]-'0'));
        }
        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
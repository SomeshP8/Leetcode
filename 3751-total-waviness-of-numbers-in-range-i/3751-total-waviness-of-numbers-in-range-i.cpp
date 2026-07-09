class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int c=0;
        for(int i=num1;i<=num2;i++){
            string s=to_string(i);
            int n=s.length();
            if(n<3) continue;
            for(int j=1;j<n-1;j++){
                if(s[j]>s[j-1] && s[j]>s[j+1]) c++;
                else if(s[j]<s[j-1] && s[j]<s[j+1]) c++;
            }
        }
        return c;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
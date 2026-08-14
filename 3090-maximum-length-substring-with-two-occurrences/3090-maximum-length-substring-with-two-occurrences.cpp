class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>freq(26,0);
        int start=0,res=0;
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a';
            while(freq[idx]>=2){
                freq[s[start]-'a']--;
                start++;
            }
            freq[idx]++;
            res=max(res,i-start+1);
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
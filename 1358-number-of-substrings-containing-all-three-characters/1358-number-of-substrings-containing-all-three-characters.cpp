class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int last[3]={-1,-1,-1};
        int cnt=0;
        for(int i=0;i<n;i++){
           last[s[i]-'a']=i;
           if(last[0]!=-1 && last[1]!=-1 && last[2]!=-1){
            cnt+=(1+min({last[0],last[1],last[2]}));
           }
        }
        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
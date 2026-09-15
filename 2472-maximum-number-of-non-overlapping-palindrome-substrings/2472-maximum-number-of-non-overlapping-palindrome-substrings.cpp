class Solution {
public:
    vector<vector<bool>>ispalindrome;
    vector<int>t;
    int solve(string &s,int len,int k){
        if(len<k) return 0;
        if(t[len]!=-1) return t[len];
        int result=solve(s,len-1,k);
        int j=len-1;
        for(int i=0;j-i+1>=k;i++){
            if(ispalindrome[i][j]){
                result=max(result,1+solve(s,i,k));
            }
        }
        return t[len]=result;
    }
    int maxPalindromes(string s, int k) {
        int n=s.length();
        ispalindrome.assign(n+1,vector<bool>(n+1,false));
        for(int L=1;L<=n;L++){
            for(int i=0;i+L<=n;i++){
                int j=i+L-1;
                if(i==j){
                    ispalindrome[i][j]=true;
                }
                else if(i+1==j){
                    ispalindrome[i][j]=(s[i]==s[j]);
                }
                else {
                    ispalindrome[i][j]=((s[i]==s[j]) && ispalindrome[i+1][j-1]==true);
                }
            }
        }
        t.assign(n+1,-1);
        return solve(s,n,k);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
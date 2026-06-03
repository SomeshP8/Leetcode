class Solution {
public:
    void somesh(int open,int close,int n,string s,vector<string>& ans){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n)
        somesh(open+1,close,n,s+"(",ans);
        if(close<open)
        somesh(open,close+1,n,s+")",ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        somesh(0,0,n,"",ans);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna
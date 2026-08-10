class Solution {
public:
  vector<int>gen(int row){
    long long ans=1;
    vector<int>res;
    res.push_back(1);
    for(int col=1;col<row;col++){
        ans=ans*(row-col);
        ans=ans/(col);
        res.push_back(ans);
    }
    return res;
  }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(gen(i));
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
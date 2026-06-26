class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>res(n,0);
        int balls=0,moves=0;
        for(int i=0;i<n;i++){
            res[i]+=moves;
            if(boxes[i]=='1') balls++;
            moves+=balls;
        }
        balls=0;
        moves=0;
        for(int i=n-1;i>=0;i--){
            res[i]+=moves;
            if(boxes[i]=='1') balls++;
            moves+=balls;
        }
      return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
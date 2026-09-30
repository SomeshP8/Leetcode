class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
      int n=seq.length();
      vector<int>somesh(n);
      int depth=0;
      for(int i=0;i<n;i++){
        if(seq[i]=='('){
          depth++;
          somesh[i]=depth%2;
        }
        else {
            somesh[i]=depth%2;
            depth--;
        }
      }
      return somesh;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
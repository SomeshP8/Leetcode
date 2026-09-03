class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n=s.length();
      int maxi=0;
      int left=0;
      vector<int>charc(128,-1);
      for(int right=0;right<n;right++){
        char c=s[right];
        if(charc[c]>=left){
            left=charc[c]+1;
        }
        charc[c]=right;
        maxi=max(maxi,right-left+1);
      }
      return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
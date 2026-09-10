class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n=s.length();
      int left=0,maxi=0;
      vector<int>arr(256,-1);
      for(int right=0;right<n;right++){
        if(arr[s[right]]>=left){
            left=arr[s[right]]+1;
        }
        arr[s[right]]=right;
        maxi=max(maxi,right-left+1);
      }
      
      return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
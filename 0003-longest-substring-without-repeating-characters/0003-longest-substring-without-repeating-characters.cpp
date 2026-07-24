class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        
        vector<int> charIndex(128, -1); 
        
        int left = 0; 
        
        for (int right = 0; right < n; right++) {
            char c = s[right];
          
            if (charIndex[c] >= left) {
        
                left = charIndex[c] + 1;
            }
            
            charIndex[c] = right;
            
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
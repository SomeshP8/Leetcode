class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0;
        int max_freq = 0;
        int maxi = 0;
        for (int right = 0; right < s.length(); right++) {
            freq[s[right] - 'A']++;
            max_freq = max(max_freq, freq[s[right] - 'A']);
            while ((right - left + 1) - max_freq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
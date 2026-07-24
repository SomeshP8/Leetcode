class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l = 0, r = 0, m = 0;
        int n = s.size();
        while (r < n) {
            if (st.find(s[r]) == st.end()) {
                st.insert(s[r]);
                m = max(m, r - l + 1);
                r++;
            } else {
                st.erase(s[l]);
                l++;
            }
        }
        return m;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
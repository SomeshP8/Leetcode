class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        int ans = 0;

        bool firstEven = (n1 % 2 == 0);
        bool secondEven = (n2 % 2 == 0);

        if (firstEven && secondEven)
            return ans;

        else if (firstEven) {
            for (int i = 0; i < n1; i++) {
                ans = ans ^ nums1[i];
            }
        } else if (secondEven) {
            for (int i = 0; i < n2; i++) {
                ans = ans ^ nums2[i];
            }
        } else {
            for (int i = 0; i < n1; i++) {
                ans = ans ^ nums1[i];
            }
            for (int i = 0; i < n2; i++) {
                ans = ans ^ nums2[i];
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
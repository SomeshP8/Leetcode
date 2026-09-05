class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
          return atMost(nums, k) - atMost(nums, k - 1);
    }
     private:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int left = 0;
        int sum = 0;
        int count = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += (nums[right]%2);
            while (sum > k) {
                sum -=(nums[left]%2);
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int currentSum = 0;
        for (int i = 0; i < k; i++) {
            currentSum += cardPoints[i];
        }
        int maxSum = currentSum;
        for (int i = 0; i < k; i++) {
            currentSum -= cardPoints[k - 1 - i];  
            currentSum += cardPoints[n - 1 - i];  
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
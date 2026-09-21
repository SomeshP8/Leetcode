class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> res(k, 0);
        vector<long long> prev(k, 0);

        for (int i = 0; i < n; i++) {
            vector<long long> curr(k, 0);

            int cr = nums[i] % k;
            curr[cr]++;

            for (int r = 0; r < k; r++) {
                int nr = ((long long)r * nums[i]) % k;
                curr[nr] += prev[r];
            }
            prev = move(curr);

            for (int x = 0; x < k; x++) {
                res[x] += prev[x];
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
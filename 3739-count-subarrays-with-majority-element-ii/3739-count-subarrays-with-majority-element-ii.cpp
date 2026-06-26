class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<int> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) prefix[i + 1] = prefix[i] + 1;
            else prefix[i + 1] = prefix[i] - 1;
        }

        vector<int> all = prefix;
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        vector<int> bit(all.size() + 1, 0);

        auto update = [&](int i) {
            for (; i < bit.size(); i += i & -i) bit[i]++;
        };

        auto query = [&](int i) {
            long long s = 0;  // FIX
            for (; i > 0; i -= i & -i) s += bit[i];
            return s;
        };

        long long ans = 0;  // FIX

        for (int i = 0; i <= n; i++) {
            int idx = lower_bound(all.begin(), all.end(), prefix[i]) - all.begin() + 1;
            ans += query(idx - 1);
            update(idx);
        }

        return ans; 
    }
}; 
    

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
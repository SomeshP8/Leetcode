class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& c, int target, int idx, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (idx == c.size() || target < 0)
            return;

        temp.push_back(c[idx]);
        solve(c, target - c[idx], idx, temp);
        temp.pop_back();

        solve(c, target, idx + 1, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates, target, 0, temp);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
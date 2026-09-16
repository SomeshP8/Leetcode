class Solution {
public:
    vector<long long> evens, odds;
    string cur = "";
    void dfs(int l, int r){
        if (l > r){
            long long next = stoll(cur);
            if (next % 2) odds.push_back(next);
            else evens.push_back(next);
        }
        else{
            for (char i = l == 0 ? '1' : '0'; i <= '9'; ++i){
                cur[l] = i;
                cur[r] = i;
                dfs(l + 1, r - 1);
            }
        }
    }
    long long minOperations(vector<int>& nums) {
        long long ans = 0;
        int m = *max_element(nums.begin(), nums.end());
        int d = 0;
        for (; m; m/= 10) ++d;
        for (int i = 1; i <= d; ++i){
            cur.resize(i);
            dfs(0, i - 1);
        }
        for (auto& n : nums){
            vector<long long>& v = n % 2 ? odds : evens;
            auto it = lower_bound(v.begin(), v.end(), n);
            long long next = INT_MAX;
            if (it != v.end()){
                next = ((long long) *it - n) / 2;
            }
            if (it != v.begin()){
                it = prev(it);
                next = min(next, (n - (long long) *it) / 2);
            }
            ans += next;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
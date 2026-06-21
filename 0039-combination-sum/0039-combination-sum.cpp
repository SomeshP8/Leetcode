#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int i, int t, vector<int>& a, vector<int>& c, vector<vector<int>>& r) {
        if (t == 0) {
            r.push_back(c);
            return;
        }
        if (i >= a.size() || t < 0) return;

        if (a[i] <= t) {
            c.push_back(a[i]);
            f(i, t - a[i], a, c, r);
            c.pop_back();
        }

        f(i + 1, t, a, c, r);
    }

    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        vector<vector<int>> r;
        vector<int> c;
        f(0, t, a, c, r);
        return r;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
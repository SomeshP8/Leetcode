class Solution {
public:
    int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> count;
    int maxi = 0,l = 0;
    for (int r = 0; r < fruits.size(); ++r) {
        count[fruits[r]]++;
        while (count.size() > 2) {
            count[fruits[l]]--;
            if (count[fruits[l]] == 0) {            
              count.erase(fruits[l]);
            }
            l++;
        }
        maxi = max(maxi, r - l + 1);
    }
    return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
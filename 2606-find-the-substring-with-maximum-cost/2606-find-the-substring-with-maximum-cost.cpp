class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = s.size();
        vector<int> cost(26);
        for (int i = 0; i < 26; i++)
            cost[i] = i + 1;
        for (int i = 0; i < chars.size(); i++)
            cost[chars[i] - 'a'] = vals[i];
        int ms = 0, md = 0;
        for (int i = 0; i < n; i++) {
            md += cost[s[i] - 'a'];
            if (md < 0) {
                md = 0;
            }
            if (ms < md) {
                ms = md;
            }
        }
        return ms;
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n + 1);

        
        for (auto &r : roads) {
            int u = r[0], v = r[1], w = r[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<bool> visited(n + 1, false);
        int ans = INT_MAX;

       
        function<void(int)> dfs = [&](int node) {
            visited[node] = true;

            for (auto &it : graph[node]) {
                int nei = it.first;
                int wt = it.second;

                ans = min(ans, wt);

                if (!visited[nei]) {
                    dfs(nei);
                }
            }
        };

        dfs(1);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
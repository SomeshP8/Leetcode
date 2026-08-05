class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<bool> suspicious(n, false);
        function<void(int)> dfs = [&](int u) {
            suspicious[u] = true;
            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    dfs(v);
                }
            }
        };
        dfs(k);
        bool canRemove = true;
        for (const auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            
            if (!suspicious[u] && suspicious[v]) {
                canRemove = false; 
                break;
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (canRemove) {
                if (!suspicious[i]) {
                    result.push_back(i);
                }
            } else {
                result.push_back(i);
            }
        } 
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
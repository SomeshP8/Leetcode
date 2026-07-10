class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> S = nums;
        sort(S.begin(), S.end());
        
        int m = S.size();
        int LOG = 18;
        vector<vector<int>> up(m, vector<int>(LOG));
        
       
        for (int i = 0; i < m; ++i) {
          
            auto it = upper_bound(S.begin(), S.end(), S[i] + maxDiff);
            up[i][0] = distance(S.begin(), prev(it));
        }
        
        for (int k = 1; k < LOG; ++k) {
            for (int i = 0; i < m; ++i) {
                up[i][k] = up[ up[i][k - 1] ][ k - 1 ];
            }
        }
        
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            
            if (u == v) {
                answer.push_back(0);
                continue;
            }
            
            int start_val = min(nums[u], nums[v]);
            int target_val = max(nums[u], nums[v]);
         
            if (start_val == target_val) {
                answer.push_back(1);
                continue;
            }
            
            int curr = lower_bound(S.begin(), S.end(), start_val) - S.begin();
            
            if (S[up[curr][LOG - 1]] < target_val) {
                answer.push_back(-1);
                continue;
            }
            
            int jumps = 0;
 
            for (int k = LOG - 1; k >= 0; --k) {
                if (S[up[curr][k]] < target_val) {
                    curr = up[curr][k];
                    jumps += (1 << k);
                }
            }
            answer.push_back(jumps + 1);
        }
        
        return answer;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
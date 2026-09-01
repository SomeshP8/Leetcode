class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int sx = -1, sy = -1;
        vector<pair<int, int>> litters;
        int litter_id[20][20];
        memset(litter_id, -1, sizeof(litter_id));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (classroom[i][j] == 'L') {
                    litter_id[i][j] = litters.size();
                    litters.push_back({i, j});
                }
            }
        }
        
        int k = litters.size();
        int full_mask = (1 << k) - 1;
        if (full_mask == 0) return 0;
        
        int best_energy[20][20][1024];
        memset(best_energy, -1, sizeof(best_energy));
        queue<tuple<int, int, int, int, int>> q;
        q.push({0, sx, sy, 0, energy});
        best_energy[sx][sy][0] = energy;
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [steps, r, c, mask, e] = q.front();
            q.pop();
            
            if (mask == full_mask) {
                return steps;
            }
            if (e == 0) continue;
            
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                    continue;
                }
                
                int ne = e - 1;
                int nmask = mask;
                if (classroom[nr][nc] == 'L') {
                    nmask |= (1 << litter_id[nr][nc]);
                }
                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }
                if (ne > best_energy[nr][nc][nmask]) {
                    best_energy[nr][nc][nmask] = ne;
                    q.push({steps + 1, nr, nc, nmask, ne});
                }
            }
        }       
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
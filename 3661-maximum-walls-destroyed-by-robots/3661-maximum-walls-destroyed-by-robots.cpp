class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        
        vector<pair<int,int>> r;
        for (int i = 0; i < n; i++) {
            r.push_back({robots[i], distance[i]});
        }
        
        sort(r.begin(), r.end());
        sort(walls.begin(), walls.end());
        
        unordered_set<int> destroyed;
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            int pos = r[i].first;
            int dist = r[i].second;
            
            int prev = (i == 0 ? INT_MIN : r[i-1].first);
            int next = (i == n-1 ? INT_MAX : r[i+1].first);
            
            int L1 = max(pos - dist, prev + 1);
            int R1 = pos;
            
            int L2 = pos;
            int R2 = min(pos + dist, next - 1);
            
            vector<int> leftWalls, rightWalls;
            
            // collect left walls
            auto it1 = lower_bound(walls.begin(), walls.end(), L1);
            auto it2 = upper_bound(walls.begin(), walls.end(), R1);
            for (auto it = it1; it != it2; it++) {
                if (!destroyed.count(*it)) leftWalls.push_back(*it);
            }
            
            // collect right walls
            it1 = lower_bound(walls.begin(), walls.end(), L2);
            it2 = upper_bound(walls.begin(), walls.end(), R2);
            for (auto it = it1; it != it2; it++) {
                if (!destroyed.count(*it)) rightWalls.push_back(*it);
            }
            
            if (leftWalls.size() > rightWalls.size()) {
                for (int w : leftWalls) destroyed.insert(w);
                ans += leftWalls.size();
            } else {
                for (int w : rightWalls) destroyed.insert(w);
                ans += rightWalls.size();
            }
        }
        
        return ans;
    }
};
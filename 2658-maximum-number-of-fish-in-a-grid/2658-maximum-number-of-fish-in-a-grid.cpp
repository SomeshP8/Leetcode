class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return 0;
        int fish = grid[i][j];
        grid[i][j] = 0;
        fish += dfs(grid, i+1, j);
        fish += dfs(grid, i-1, j);
        fish += dfs(grid, i, j+1);
        fish += dfs(grid, i, j-1);
        return fish;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] > 0) {
                    maxi = max(maxi, dfs(grid, i, j));
                }
            }
        }
        return maxi;
    }
};
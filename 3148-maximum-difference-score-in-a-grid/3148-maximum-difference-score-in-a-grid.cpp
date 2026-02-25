class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>mini(n,vector<int>(m));
        int ans=INT_MIN;
        mini[0][0]=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;
                int best=INT_MAX;
                if(i>0) best=min(best,mini[i-1][j]);
                if(j>0) best=min(best,mini[i][j-1]);
              ans=max(ans,grid[i][j]-best);
              mini[i][j]=min(grid[i][j],best);
            }
        }
        return ans;
    }
};
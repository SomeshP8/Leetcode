class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        long long total=0;
        for(int i=0;i<n;i++){
                total+=accumulate(grid[i].begin(),grid[i].end(),0LL);
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0 && (total-sum)==sum) return true;
                sum+=grid[i][j];
            }
        }
        sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0 && (total-sum)==sum) return true;
                sum+=grid[j][i];
            }
        }
        return false;
    }
};
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        const int mod=1e9+7;
        vector<vector<long long>>maxi(n,vector<long long>(m));
        vector<vector<long long>>mini(n,vector<long long>(m));
        maxi[0][0]=mini[0][0]=grid[0][0];
        // first row
        for(int j=1;j<m;j++){
            maxi[0][j]=mini[0][j]=maxi[0][j-1]*grid[0][j];
        }
        // first col
        for(int i=1;i<n;i++){
            maxi[i][0]=mini[i][0]=maxi[i-1][0]*grid[i][0];
        }
        for(int i=1;i<n;i++){
          for(int j=1;j<m;j++){
             long long val=grid[i][j];
            long long a=maxi[i][j-1]*val;
            long long b=mini[i][j-1]*val;
            long long c=maxi[i-1][j]*val;
            long long d=mini[i-1][j]*val;
            maxi[i][j]=max({a,b,c,d});
            mini[i][j]=min({a,b,c,d});
          }
        }
        long long res=maxi[n-1][m-1];
        if(res<0) return -1;
        return res%mod;
    }
};
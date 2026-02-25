class Solution {
public:
    int ans=INT_MAX;
    int dist(pair<int,int>a,pair<int,int>b){
      return abs(a.first-b.first)+abs(a.second-b.second);
    }
    void solve(int i,vector<pair<int,int>>&extra,vector<pair<int,int>>&zero,vector<int>&used,int cost){
        if(i==extra.size()){
            ans=min(ans,cost);
            return;
        }
        for(int j=0;j<zero.size();j++){
            if(!used[j]){
                used[j]=1;
            solve(i+1,extra,zero,used,cost+dist(extra[i],zero[j]));
            used[j]=0;
            }
        }
    }
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int,int>>extra,zero;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0)
                 zero.push_back({i, j});
                 else if(grid[i][j]>1){
                    for(int k=1;k<grid[i][j];k++)
                     extra.push_back({i,j});
                 }
            }
        }
        vector<int>used(zero.size(),0);
        solve(0,extra,zero,used,0);
        return ans;
    }
};
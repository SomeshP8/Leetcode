class Solution {
public:
    vector<vector<vector<int>>> dp;     
    vector<vector<vector<int>>> vis;      
    int somesh(vector<vector<int>>&grid,int k,int i,int j,int sum){
    int n=grid.size(),m=grid[0].size();
    int add,sum1;
    if(grid[i][j]==0){
        add=0;
        sum1=0;
    }
    else if(grid[i][j]==1){
        add=1;
        sum1=1;
    }
    else {
        add=2;
        sum1=1;
    }
    sum+=sum1;
    if(sum>k) return INT_MIN;
    if(i==n-1 && j==m-1) return add;
    if(vis[i][j][sum]) return dp[i][j][sum];  
    vis[i][j][sum]=1;                         
     int right=INT_MIN,down=INT_MIN;
     if(i+1<n)                               
        right=somesh(grid,k,i+1,j,sum);
     if(j+1<m)                                 
        down=somesh(grid,k,i,j+1,sum);
     if(right==INT_MIN && down==INT_MIN){
        return dp[i][j][sum]=INT_MIN;        
     }
     else if(right==INT_MIN){
        return dp[i][j][sum]=add+down;       
     }
     else if(down==INT_MIN){
        return dp[i][j][sum]=add+right;        
     }
     else{
        return dp[i][j][sum]=add+max(right,down); 
     }
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();
        dp.assign(n, vector<vector<int>>(m, vector<int>(k+1, 0)));  
        vis.assign(n, vector<vector<int>>(m, vector<int>(k+1, 0)));  
        int ans=somesh(grid,k,0,0,0);
        if(ans==INT_MIN) return -1;
        else return ans;
    }
};
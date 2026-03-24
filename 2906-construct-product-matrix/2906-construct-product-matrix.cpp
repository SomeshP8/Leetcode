class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int mod=12345;
        vector<int>nums;
        for(auto &row:grid){
            for(auto &x:row){
                nums.push_back(x%mod);
            }
        }
        int size=nums.size();
        vector<int>prefix(size,1),suffix(size,1);
        for(int i=1;i<size;i++){
            prefix[i]=(prefix[i-1]*nums[i-1])%mod;
        }
        for(int i=size-2;i>=0;i--){
            suffix[i]=(suffix[i+1]*nums[i+1])%mod;
        }
        vector<vector<int>>res(n,vector<int>(m));
        int idx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i][j]=(prefix[idx]*suffix[idx])%mod;
                idx++;
           }
        }
        return res;
    }
};
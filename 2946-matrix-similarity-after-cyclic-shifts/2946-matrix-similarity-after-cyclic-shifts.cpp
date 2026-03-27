class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        k%=m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i%2==1){
                int sc=(j+k)%m;
                if(mat[i][j]!=mat[i][sc]){
                    return false;
                }
            }
            if(i%2==0){
                int sc=(j-k+m)%m;
                if(mat[i][j]!=mat[i][sc]){
                    return false;
                }
            }
        }
    }
    return true;
  }
};
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int>prev_height(cols,0);
        int res=0;
        for(int r=0;r<rows;r++){
            vector<int>height(cols);
            for(int c=0;c<cols;c++){
                if(matrix[r][c]==0){
                    height[c]=0;
                }
                else{
                    height[c]=prev_height[c]+1;
                }
            }
        vector<int>sorted=height;
        sort(sorted.begin(),sorted.end(),greater<int>());
        for (int i=0;i<cols;i++) {
                res=max(res,sorted[i]*(i + 1));
            }
            prev_height=height;
        }
    return res;
    }
};
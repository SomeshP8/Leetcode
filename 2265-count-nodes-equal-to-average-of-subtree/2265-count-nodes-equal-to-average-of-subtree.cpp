
class Solution {
public:
    int c=0;
    pair<int,int>dfs(TreeNode* root){
        if(!root) return{0,0};
        auto left=dfs(root->left);
        auto right=dfs(root->right);
        int sum=0,cnt=0;
        sum=left.first+right.first+root->val;
        cnt=left.second+right.second+1;
        if((sum/cnt)==root->val) c++;
        return {sum,cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return c;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
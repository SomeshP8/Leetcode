/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* node,int c){
        if(!node) return 0;
        c = c * 2 + node->val;
        if(!node->left && !node->right)
        return c;
          return dfs(node->left,c)+dfs(node->right,c);
    }
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};
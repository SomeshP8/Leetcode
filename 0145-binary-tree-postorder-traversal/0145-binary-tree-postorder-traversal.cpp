class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;        
    }
private:
    void postorder(TreeNode* node, std::vector<int>& res) {
        if (node == nullptr) {
            return;
        }
        postorder(node->left,res);
        postorder(node->right, res);
        res.push_back(node->val);
    }    
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
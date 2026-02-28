class Solution {
public:
    int diameter(Node* root) {
        int dia=0;
        height(root, dia);
        return dia;
    }
    private:
      int height(Node* node, int &dia){
        if(!node) return 0;
        int lh=height(node->left,dia);
        int rh=height(node->right,dia);
        dia=max(dia,lh+rh);
        return 1+max(lh,rh);
      }
};
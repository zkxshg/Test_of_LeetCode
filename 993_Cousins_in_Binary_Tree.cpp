// Search x depth (return -1 when same parents)-> Search y depth -> compare
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        if (!(root->left) && !(root->right)) return false;
        if (root->val == x || root->val == y) return false;
        
        int depth = 0;
        int x_dep = searchDep (root, depth, x, y);
        if (x_dep == -1) return false;  
        int y_dep = searchDep (root, depth, y, x);
        if (x_dep == -1) return false;
        if (x_dep == y_dep) return true;
        return false;
    }
    
    int searchDep(TreeNode* root, int dep, int x, int y){
        
        if (!(root->left) && !(root->right)) return -2;
        int leftSearch = -3;
        int rightSearch = -3;
        if (root->left && root->right){
            if (root->left->val == x) {
                if (root->right->val == y) return -1;
                else return dep + 1;
            }
            else if (root->right->val == x) {
                if (root->left->val == y) return -1;
                else return dep + 1;
            }
            leftSearch = searchDep(root->left, dep+1, x, y);
            rightSearch = searchDep(root->right, dep+1, x, y);
        }
        else if (root->left) {
            if (root->left->val == x) return dep + 1;
            leftSearch = searchDep(root->left, dep+1, x, y);
        }
        else {
            if (root->right->val == x) return dep + 1;
            rightSearch = searchDep(root->right, dep+1, x, y);
        }
        
        if (leftSearch > 0 || leftSearch == -1) return leftSearch;
        else if (rightSearch > 0 || rightSearch == -1) return rightSearch;
        
        return -2; 
    }
};

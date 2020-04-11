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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            TreeNode* result = new TreeNode(val);
            return result;
        }
        insertV(root, val);
        return root; 
    }
    void insertV(TreeNode* root, int val){
        TreeNode* result = new TreeNode(val);
        if (!(root->left) && !(root->right)){
            if (root->val > val) root->left = result;
            else root->right = result;
        }
        else if (root->val > val){
            if (!root->left) root->left = result;
            else insertV(root->left, val);
        }
        else{
            if (!root->right) root->right = result;
            else insertV(root->right, val);
        }
    }
};

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int len = preorder.size();
        if (len == 0) return NULL;
        
        TreeNode * root = new TreeNode(preorder[0]);
        for (int i = 1; i < len; i++) insertNode(root, preorder[i]);
        return root;
    }
    
    void insertNode(TreeNode* root, int pre) {
        int rval = root->val;
        if (pre < rval) {
            if (root->left) insertNode(root->left, pre);
            else {
                TreeNode * rleft = new TreeNode(pre);
                root->left = rleft;
            }
        }
        else {
            if (root->right) insertNode(root->right, pre);
            else {
                TreeNode * rright = new TreeNode(pre);
                root->right = rright;
            }
        }
    }
};

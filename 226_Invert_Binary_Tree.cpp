// swap iteratively
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        if (!(root->left) && !(root->right)) return root;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        temp = invertTree(root->left);
        temp = invertTree(root->right);
        return root;
    }
};

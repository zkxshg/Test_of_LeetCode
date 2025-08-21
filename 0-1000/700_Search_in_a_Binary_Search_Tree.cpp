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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;
        else if (root->val == val) return root;
        else if (!(root->left) && !(root->right)) return NULL;
        TreeNode* aim = searchV(root, val, aim);
        return aim;
    }
    TreeNode* searchV(TreeNode* root, int val, TreeNode* aim){
        if (root->val == val) return root;
        else{
            TreeNode* tempN;
            if (root->left) tempN = searchV(root->left, val, aim);
            if (tempN) return tempN;
            if (root->right) return searchV(root->right, val, aim);
        }
        return NULL;
    }
};

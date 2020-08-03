// DFS
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 0;
        int result = 0;
        if (root->left && !root->left->left && !root->left->right) result += root->left->val;
        else result += sumOfLeftLeaves(root->left);
        result += sumOfLeftLeaves(root->right);
        return result;
    }
};

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

// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/
// DFS

class Solution {
public:
    int dfsLeft(TreeNode* root, int len) {
        int res = len;
        if (root->right) res = max(res, dfsRight(root->right, len + 1));
        if (root->left) res = max(res, dfsLeft(root->left, 1));
        return res;
    }

    int dfsRight(TreeNode* root, int len) {
        int res = len;
        if (root->left) res = max(res, dfsLeft(root->left, len + 1));
        if (root->right) res = max(res, dfsRight(root->right, 1));
        return res;
    }

    int longestZigZag(TreeNode* root) {
        int res = 0;
        if (root->left) res = max(res, dfsLeft(root->left, 1));
        if (root->right) res = max(res, dfsRight(root->right, 1));
        return res;
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

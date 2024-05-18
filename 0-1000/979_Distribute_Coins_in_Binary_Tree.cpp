// https://leetcode.com/problems/distribute-coins-in-binary-tree/?envType=daily-question&envId=2024-05-18
// DFS

class Solution {
public:
    int res;

    int dfs(TreeNode* root) {
        int tem = root->val - 1;
        if (root->left) tem += dfs(root->left);
        if (root->right) tem += dfs(root->right);
        
        res += abs(tem);
        return tem;
    }


    int distributeCoins(TreeNode* root) {
        res = 0;
        int d = dfs(root);
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

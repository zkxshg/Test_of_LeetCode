// https://leetcode.com/problems/binary-tree-tilt/
// DFS

class Solution {
public:
    int res;
    
    int dfs(TreeNode* root) {
        int lv = 0, rv = 0;
        
        if (root->left) lv = dfs(root->left);
        if (root->right) rv = dfs(root->right);
        
        res += abs(lv - rv);
        
        return lv + rv + root->val;
    }
    
    int findTilt(TreeNode* root) {
        if (!root) return 0;
        
        res = 0;
        int r = dfs(root);
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

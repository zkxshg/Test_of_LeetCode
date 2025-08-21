// https://leetcode.com/problems/find-largest-value-in-each-tree-row/
// dfs

class Solution {
public:
    vector<int> lgst;
    
    int depth(TreeNode* root, int lv) {
        int res = lv;
        if (root->left) res = max(res, depth(root->left, lv + 1));
        if (root->right) res = max(res, depth(root->right, lv + 1));
        return res;
    }
    
    void dfs(TreeNode* root, int lv) {
        lgst[lv] = max(lgst[lv], root->val);
        
        if (root->right) dfs(root->right, lv + 1);
        if (root->left) dfs(root->left, lv + 1);
    }
        
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        
        int dep = depth(root, 0);
        
        lgst.resize(dep + 1, INT_MIN);
        
        dfs(root, 0);
        
        return lgst;
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

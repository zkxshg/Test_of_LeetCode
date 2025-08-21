// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
// dfs

class Solution {
public:
    set<int> nodes;
    
    void dfs(TreeNode* root) {
        nodes.insert(root->val);
        
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        if (nodes.size() < 2) return -1;
        auto it = nodes.begin();
        advance(it, 1);
        return *it;
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

// https://leetcode.com/problems/binary-tree-pruning/
// DFS

class Solution {
public:
    bool ifOne(TreeNode* root) {
        bool one = root->val ? true : false;
        
        if (root->left) {
            if (ifOne(root->left)) one = true;
            else root->left = NULL;
        }
        
        if (root->right) {
            if (ifOne(root->right)) one = true;
            else root->right = NULL;
        }
        
        return one;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if (ifOne(root)) return root;
        return NULL;
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

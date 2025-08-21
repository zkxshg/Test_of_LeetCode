// https://leetcode.com/problems/count-good-nodes-in-binary-tree/
// DFS

class Solution {
public:
    int res;
    
    void countGood(TreeNode* root, int maxPre) {
        if (root->val >= maxPre) {
            maxPre = root->val; res++;
        }
        
        if (root->left) countGood(root->left, maxPre);
        if (root->right) countGood(root->right, maxPre);
    }
    
    int goodNodes(TreeNode* root) {
        res = 0;
        countGood(root, root->val);
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

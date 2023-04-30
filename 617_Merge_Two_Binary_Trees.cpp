// https://leetcode.com/problems/merge-two-binary-trees/
// DFS

class Solution {
public:
    void addTree(TreeNode* root1, TreeNode* root2) {
        root1->val += root2->val;
        
        if (root1->left || root2->left) {
            if (!root1->left) root1->left = new TreeNode(0);
            if (!root2->left) root2->left = new TreeNode(0);
            addTree(root1->left, root2->left);
        }
        
        if (root1->right || root2->right) {
            if (!root1->right) root1->right = new TreeNode(0);
            if (!root2->right) root2->right = new TreeNode(0);
            addTree(root1->right, root2->right);
        }
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root2) return root1;
        if (!root1) return root2;
        
        addTree(root1, root2);
        
        return root1;
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

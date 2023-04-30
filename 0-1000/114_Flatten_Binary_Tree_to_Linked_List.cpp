// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
//  pre-order traversal / DFS
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root && (root->left || root->right)) TreeNode* rLeaf = attch(root);
    }
    
    TreeNode* attch(TreeNode* root){
        if (!root->left && !root->right) return root;
        
        TreeNode* lLeaf =  root;
        if (root->left) lLeaf = attch(root->left);
        
        TreeNode* rLeaf =  root;
        if (root->right) {
            rLeaf = attch(root->right);
            lLeaf->right = root->right;
        }
        else {
            root->right = root->left;
            root->left = NULL;
            return lLeaf;
        }

        if (root->left) {
            root->right = root->left;
            root->left = NULL;
        }
        return rLeaf;
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

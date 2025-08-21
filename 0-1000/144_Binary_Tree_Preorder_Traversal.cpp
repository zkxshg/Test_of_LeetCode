// https://leetcode.com/problems/binary-tree-preorder-traversal/
// same to 145. Binary Tree Postorder Traversal
// Preorder: root->left->right
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        recSearch(root, result);
        return result;
    }
    void recSearch(TreeNode* root, vector<int> & result){
        if (root){
            result.push_back(root->val);
            if (root->left) recSearch(root->left, result);
            if (root->right) recSearch(root->right, result);
        }
    }
};

// https://leetcode.com/problems/binary-tree-postorder-traversal/
// Similar to 590. N-ary Tree Postorder Traversal
// Postorder: left->right->root
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        recSearch(root, result);
        return result;
    }
    void recSearch(TreeNode* root, vector<int> & result){
        if (root){
            if (root->left) recSearch(root->left, result);
            if (root->right) recSearch(root->right, result);
            result.push_back(root->val);
        }
    };
};

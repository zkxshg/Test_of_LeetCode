// same to 145. Binary Tree Postorder Traversal
// Inorder: left->root->right
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        recSearch(root, result);
        return result;
    }
    void recSearch(TreeNode* root, vector<int> & result){
        if (root){
            if (root->left) recSearch(root->left, result);
            result.push_back(root->val);
            if (root->right) recSearch(root->right, result);
        }
    }
};

// DFS
class Solution {
public:
    int cam;
    
    int minCameraCover(TreeNode* root) {
        cam = 0;
        count(root);
        if (!root->val) cam++;
        return cam;
    }
    
    void count(TreeNode* root) {
        if (!root->left && !root->right) return;
        
        if (root->left) count(root->left);
        if (root->right) count(root->right);
        
        if ((root->left && root->left->val == 1) || (root->right && root->right->val == 1))
            root->val = -1;
        
        if ((root->left && !root->left->val) || (root->right && !root->right->val)) {
            root->val = 1; cam++;
        }
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

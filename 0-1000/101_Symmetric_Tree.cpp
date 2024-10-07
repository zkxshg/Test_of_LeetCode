// https://leetcode.com/problems/symmetric-tree/0-1000/
// recursively and iteratively
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        
        if (!(root->left) && !(root->right)) return true;
        else if (!(root->left) || !(root->right)) return false;
        
        bool Symm = isMirror(root->left, root->right);
        return Symm;
    }
    
    bool isMirror(TreeNode* leftn, TreeNode* rightn){
        if (!(leftn) && !(rightn)) return true;
        
        if(leftn->val != rightn->val) return false;
        
        if (!(leftn->left) || !(rightn->right)) {
            if (leftn->left || rightn->right) return false;
        }
        
        if (!(leftn->right) || !(rightn->left)) {
            if (leftn->right || rightn->left) return false;
        }
        
        bool Mirr = isMirror(leftn->left , rightn->right);
        if (Mirr == false) return false;
        
        Mirr = isMirror(leftn->right , rightn->left);
        return Mirr;
    }
};

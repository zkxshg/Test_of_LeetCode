// https://leetcode.com/problems/delete-node-in-a-bst/
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (!(root->left) && !(root->right) && root->val == key) return NULL;
        
        TreeNode* aim = searchV(root, key);
        if (!aim) return root;
        
        if (!(aim->left) && !(aim->right)){
            delNode(root, aim);
            return root;
        }
        else if (!(aim->left) || !(aim->right)) {
            if (aim->left) {
                aim->val = aim->left->val;
                aim->right = aim->left->right;
                aim->left = aim->left->left;
            }
            else {
                aim->val = aim->right->val;
                aim->left = aim->right->left;
                aim->right = aim->right->right;   
            }
            return root;
        }
        
        TreeNode* aimL = aim->left, *aimR = aim->right, *nex = aim;
        
        aim->val = aimL->val;
        aim->left = aimL->left;
        aim->right = aimL->right;

        while (nex->right) nex = nex->right;
        nex->right = aimR;
        
        return root;
    }
    
    TreeNode* searchV(TreeNode* root, int val){
        if (root->val == val) return root;
        else if (root->val > val && root->left) return searchV(root->left, val);
        else if (root->right) return searchV(root->right, val);
        return NULL;
    }
    
    void delNode(TreeNode* root, TreeNode* aim){
        if (root->val > aim->val){
            if (root->left == aim) root->left = NULL;
            else delNode(root->left, aim);
        }
        else if (root->right == aim) root->right = NULL;
        else delNode(root->right, aim);
    }
};

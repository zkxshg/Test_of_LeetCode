// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// DFS

class Solution {
public:
    TreeNode* res;
    int lv;
    unordered_map<int, bool> ifP;
    unordered_map<int, bool> ifQ;
    
    
    bool searchP(TreeNode* root, TreeNode* p) {
        if (root == p 
            || (root->left && searchP(root->left, p)) 
            || (root->right && searchP(root->right, p))) {
            ifP[root->val] = true; return true;
        }

        return false;
    }
    
    bool searchQ(TreeNode* root, TreeNode* p) {
        if (root == p 
            || (root->left && searchQ(root->left, p)) 
            || (root->right && searchQ(root->right, p))) {
            ifQ[root->val] = true; return true;
        }

        return false;
    }
    
    void search(TreeNode* root, int l) {
        if (ifP[root->val] && ifQ[root->val]) {
            if (root->left) search(root->left, l + 1);
            if (root->right) search(root->right, l + 1);
            
            if (l > lv) {
                res = root; lv = l;
            }
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lv = 0; ifP.clear(); ifQ.clear();
        
        int l = 1;
        if (searchP(root, p) && searchQ(root, q)) search(root, l);
            
        
        return res;        
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// DFS + two pointers
class Solution {
public:
    vector<int> pre; vector<int> ino;
        
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        if (len == 0) return NULL;
        
        pre = preorder; ino = inorder;
        
        TreeNode * root = new TreeNode(0);
        insertNode(root, 0, len - 1, 0, len - 1);
        return root;
    }
    
     void insertNode(TreeNode* root, int ps, int pe, int is, int ie) {
         root->val = pre[ps];
         
         if (ps == pe) return;
         
         int pos = find(ino.begin() + is, ino.begin() + ie + 1, pre[ps]) - (ino.begin() + is);

         if (pos > 0) {
             root->left = new TreeNode(0);
             insertNode(root->left, ps + 1, ps + pos, is, is + pos - 1);
         } 
         
         if (pos < ie - is) {
             root->right = new TreeNode(0);
             insertNode(root->right, ps + pos + 1, pe, is + pos + 1, ie);
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

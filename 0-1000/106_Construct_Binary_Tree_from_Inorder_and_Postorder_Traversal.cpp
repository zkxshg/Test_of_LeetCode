// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// divide and conquer

class Solution {
public:
    void div(TreeNode* root, vector<int>& IO, vector<int>& PO, int ist, int ien, int pst, int pen) {
        if (ien < 0 || pen < 0) return;
        
        root->val = PO[pen];
        
        int ld, rd, r = PO[pen];
        
        for (int i = ist; i <= ien; i++) {
            if (IO[i] == r) {
                ld = i; break;
            }
        }
        
        if (ld > ist) {
            TreeNode* ln = new TreeNode(0);
            root->left = ln;
            div(ln, IO, PO, ist, ld - 1, pst, pst + (ld - 1 - ist));
        }
        
        if (ld < ien) {
            TreeNode* rn = new TreeNode(0);
            root->right = rn;
            div(rn, IO, PO, ld + 1, ien, pst + (ld - ist), pen - 1);
        }
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(0);
        div(root, inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
        return root;
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

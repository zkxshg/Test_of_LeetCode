// DFS
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* newR = new TreeNode(v);
            newR->left = root;
            return newR;
        }
        
        addNode(root, v, d, 1);
        
        return root;
    }
    
    void addNode(TreeNode* root, int v, int d, int lv) {
        if (lv == d - 1) {
            TreeNode* newL = new TreeNode(v);
            newL->left = root->left;
            root->left = newL; 
            
            TreeNode* newR = new TreeNode(v);
            newR->right = root->right;
            root->right = newR; 
            
        }
        else {
            if (root->left) addNode(root->left, v, d, lv + 1);
            if (root->right) addNode(root->right, v, d, lv + 1);
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

// the same as 1123 lowest-common-ancestor-of-deepest-leaves
class Solution {
public:
    TreeNode* finalR;
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root->left && !root->right) return root;
        
        int maxDep = maxL(root, 0);
        finalR = root;
        bool res = ifDeepest(root, 0, maxDep);

        return finalR;
    }
    
    int maxL(TreeNode* root, int dep) {
        if (!root->left && !root->right) return dep;
        int res = dep;
        if (root->left) res = max(res, maxL(root->left, dep + 1));
        if (root->right) res = max(res, maxL(root->right, dep + 1));
        return res;
    }
    
     bool ifDeepest(TreeNode* root, int dep, int maxD) {
         if (!root->left && !root->right) {
             if (dep == maxD) {
                 finalR = root;
                 return true;
             }
             return false;
         }
         
         bool lDeep = false, rDeep = false;
         
         if (root->left && ifDeepest(root->left, dep + 1, maxD)) lDeep = true;
         if (root->right && ifDeepest(root->right, dep + 1, maxD)) rDeep = true;
         
         if (!lDeep && !rDeep) return false;
         
         if (lDeep && rDeep) finalR = root;
         return true;
        
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

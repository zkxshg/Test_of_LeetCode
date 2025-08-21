// DP + DFS + Tree
class Solution {
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        
        vector<int> pro = maxPro(root);
     
        return pro[0];
    }
    
    vector<int> maxPro(TreeNode* root) {
        vector<int> pro(2, 0);
        
        if (!root->left && !root->right) {
            pro[0] = root->val;
            return pro;
        }
        
        vector<int> preProL(2, 0);
        
        if (root->left) {
            vector<int> leftPro = maxPro(root->left);
            preProL[0] += leftPro[0];
            preProL[1] += leftPro[1];
        }
        
        if (root->right) {
            vector<int> rightPro = maxPro(root->right);
            preProL[0] += rightPro[0];
            preProL[1] += rightPro[1];
        }
            
        pro[0] = max(preProL[1] + root->val, preProL[0]);
        pro[1] = preProL[0];
        
        return pro;
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

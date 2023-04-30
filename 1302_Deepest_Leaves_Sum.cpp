// https://leetcode.com/problems/deepest-leaves-sum/
// DFS
class Solution {
public:
    int res, maxDep;
    int deepestLeavesSum(TreeNode* root) {
        if (!root->left && !root->right) return root->val;
        
        maxDep = calDep(root, 1);
        res = 0;
        
        addMaxDep(root, 1);
        
        return res;
    }
    
    int calDep(TreeNode* root, int lv) {
        if (!root->left && !root->right) return lv;
        int le = lv, ri = lv;
        if (root->left) le = calDep(root->left, lv + 1);
        if (root->right) ri = calDep(root->right, lv + 1);
        return max(le, ri);
    }
    
    void addMaxDep(TreeNode* root, int lv) {
        if (lv == maxDep) res += root->val;
        
        if (root->left) addMaxDep(root->left, lv + 1);
        if (root->right) addMaxDep(root->right, lv + 1);
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

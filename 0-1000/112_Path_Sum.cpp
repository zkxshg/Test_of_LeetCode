// https://leetcode.com/problems/path-sum/
// DFS

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!(root->left) && !(root->right)) {
            if (root->val == sum) return true;
            else return false;
        } 
        
        bool result = false;
        int temp = 0;
        result = sumTree(root, temp, sum);
        return result;
    }
    bool sumTree(TreeNode* root, int tem, int sum){
        if (!(root->left) && !(root->right)){
            tem += root->val;
            if (tem == sum) return true;
        }
        else {
            tem += root->val;
            
            bool result = false;
            if (root->left) result = sumTree(root->left, tem, sum);
            if (result) return result;
            
            if (root->right) result = sumTree(root->right, tem, sum);
            return result;
        }
        return false;
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

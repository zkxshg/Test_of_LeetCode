// https://leetcode.com/problems/binary-tree-level-order-traversal/
// same to 107. Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> defaul;
        if (!root) return defaul;
        
        if (!(root->left) && !(root->right)) {
            vector<int> temp;
            temp.push_back(root->val);
            defaul.push_back(temp);
            return defaul;
        } 
        
        int depth = 0;
        int maxDepth = calDep(root, depth);
        
        int counter = 0;
        vector<vector<int>> result(maxDepth+1);
        travTree(root, counter, result);
        
        return result;
    }
    
    void travTree(TreeNode* root, int cou, vector<vector<int>> &res){ 
        res[cou].push_back(root->val); 
        if (root->left || root->right) {
            if (root->left) travTree(root->left, cou+1, res);  
            if (root->right) travTree(root->right, cou+1, res);  
        }
    }
    
    int calDep(TreeNode* root, int depth){
        if (!(root->left) && !(root->right)) return depth;
        
        int leftMax = -1;
        if (root->left) leftMax = calDep(root->left, depth+1);
        int rightMax = -1;
        if (root->right) rightMax = calDep(root->right, depth+1);
        
        if (leftMax > rightMax) return leftMax;
        return rightMax;
    }
};

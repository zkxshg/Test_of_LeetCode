//Extension of 102. Binary Tree Level Order Traversal
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (!root) return result;
        
        if (!(root->left) && !(root->right)) {
            result.push_back(root->val);
            return result;
        } 
        
        int depth = 0;
        int maxDepth = calDep(root, depth);
        
        int counter = 0;
        vector<vector<int>> resultarr(maxDepth+1);
        travTree(root, counter, resultarr);
        
        result.push_back(root->val);
        
        double aver = 0; 
        for (int i = 1; i < maxDepth+1; i++){
            aver = 0;
            for (int j = 0; j < resultarr[i].size(); j++) aver +=  resultarr[i][j];
            aver /= resultarr[i].size();
            result.push_back(aver);
        }
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

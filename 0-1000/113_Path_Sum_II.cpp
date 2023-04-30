// https://leetcode.com/problems/path-sum-ii/
// DFS
// vector<vector<int> > res; arr.push_back(root->val); res->push_back(arr);
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int> > result;
        vector<int> temp;
        if (!root) return result;
        
        if (!(root->left) && !(root->right)) {
            if (root->val == sum) {
                temp.push_back(sum);
                result.push_back(temp);
            }
            return result;
        }
        int emu = 0;
        sumTree(root, emu, sum, &result, temp);
        return result;
    }
    void sumTree(TreeNode* root, int tem, int sum, vector<vector<int>> * res, vector<int> arr){
        if (!(root->left) && !(root->right)){
            tem += root->val;
            if (tem == sum) {
                arr.push_back(root->val);
                res->push_back(arr);
            }
        }
        else {
            tem += root->val;
            arr.push_back(root->val);
            if (root->left) sumTree(root->left, tem, sum, res, arr);
            if (root->right) sumTree(root->right, tem, sum, res, arr);
        }
    }
};

// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
// DFS
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        vector<int> res = scan(root);
        
        int result = res[2];
        result = max(result, abs(res[0] - root->val));
        result = max(result, abs(res[1] - root->val));
        
        return result;
    }
    
    vector<int> scan(TreeNode* root) {
        int maxV = root->val, minV = root->val, res = 0;
        
        if (root->left) {
            vector<int> tem = scan(root->left);
            maxV = max(tem[0], maxV);
            minV = min(tem[1], minV);
            res  = max(tem[2], res);
        }
        
        if (root->right) {
            vector<int> tem2 = scan(root->right);
            maxV = max(tem2[0], maxV);
            minV = min(tem2[1], minV);
            res  = max(tem2[2], res);
        }
        
        res = max(res, abs(maxV - root->val));
        res = max(res, abs(minV - root->val));
        
        vector<int> ret(3);
        ret[0] = maxV; ret[1] = minV; ret[2] = res;
        return ret;
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

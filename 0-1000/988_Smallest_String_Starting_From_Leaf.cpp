// https://leetcode.com/problems/smallest-string-starting-from-leaf/
// DFS

class Solution {
public:
    string res;
    
    void dfs(TreeNode* root, string s) {
        s += ('a' + root->val);
        
        if (!root->left && !root->right) {
            string rt = "";
            rt.assign(s.rbegin(), s.rend());
            
            if (res.empty()) res = rt;
            else if (res > rt) res = rt;
            
            return;
        }
        
        if (root->left) dfs(root->left, s);
        if (root->right) dfs(root->right, s);
    }
    
    
    string smallestFromLeaf(TreeNode* root) {
        res = "";
        string tem = "";
        dfs(root, tem);
        return res;
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

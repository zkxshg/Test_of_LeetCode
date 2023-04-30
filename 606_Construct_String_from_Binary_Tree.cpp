// https://leetcode.com/problems/construct-string-from-binary-tree/
// dfs

class Solution {
public:
    string str;
    
    void dfs(TreeNode* root) {
        str += to_string(root->val);
        
        if (root->left) {
            str += '('; dfs(root->left); str += ')';
        }
        else if (root->right) str += "()";
        
        if (root->right) {
            str += '('; dfs(root->right); str += ')';
        }
    }
    
    
    string tree2str(TreeNode* root) {
        str = ""; dfs(root);
        return str;
    }
};

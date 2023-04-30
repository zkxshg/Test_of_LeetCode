// https://leetcode.com/problems/binary-tree-right-side-view/
// DFS

class Solution {
public:
    vector<TreeNode* > res;
    
    void dfs(TreeNode* root, int lv) {
        if (res.size() < lv) res.push_back(root);
        else res[lv - 1] = root;
        
        if (root->left) dfs(root->left, lv + 1);
        if (root->right) dfs(root->right, lv + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        res.clear();
        
        dfs(root, 1);
        
        vector<int> R;
        for (auto& r : res) R.push_back(r->val);
        return R;
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

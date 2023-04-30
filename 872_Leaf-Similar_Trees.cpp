// https://leetcode.com/problems/leaf-similar-trees/description/
// DFS

class Solution {
public:
    vector<int> v1;
    vector<int> v2;

    void dfs1(TreeNode* root) {
        if (!root->left && !root->right) v1.push_back(root->val);
        else {
            if (root->left) dfs1(root->left);
            if (root->right) dfs1(root->right);
        }
    }

    void dfs2(TreeNode* root) {
        if (!root->left && !root->right) v2.push_back(root->val);
        else {
            if (root->left) dfs2(root->left);
            if (root->right) dfs2(root->right);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        v1.clear(); v2.clear();
        dfs1(root1);
        dfs2(root2);
        return v1 == v2;
    }
};

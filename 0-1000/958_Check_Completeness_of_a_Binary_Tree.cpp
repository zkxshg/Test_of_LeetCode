// https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
// dfs

class Solution {
public:
    int depth;
    bool comp;
    vector<int> bot;

    int calDep(TreeNode* root, int depth) {
        int res = depth;
        if (root->left) res = max(res, calDep(root->left, depth + 1));
        if (root->right) res = max(res, calDep(root->right, depth + 1));
        return res;
    }

    void dfs(TreeNode* root, int val, int dep) {
        if (!comp) return;

        if (dep < depth - 1) {
            if (!root->left || !root->right) comp = false; // not complete binary tree
        }
        else if (dep == depth) {
            if (!bot.empty() && val != bot.back() + 1) comp = false; // not as far as left
            else bot.push_back(val);
        }

        if (root->left) dfs(root->left, 2 * val, dep + 1);
        if (root->right) dfs(root->right, 2 * val + 1, dep + 1);
    }

    bool isCompleteTree(TreeNode* root) {
        depth = calDep(root, 1);

        bot.clear(); comp = true;

        dfs(root, 0, 1);

        if (!bot.empty() && bot[0] != 0) return false;
        
        return comp;
    }
};

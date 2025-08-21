// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/
// DFS

class Solution {
public:
    int res;

    pair<int, int> dfs(TreeNode* root) {
        int sum = root->val;
        int num = 1;

        if (root->left) {
            pair<int, int> pleft = dfs(root->left);
            sum += pleft.first;
            num += pleft.second;
        }
        if (root->right) {
            pair<int, int> pright = dfs(root->right);
            sum += pright.first;
            num += pright.second;
        }

        if (root->val == sum / num) res++;

        return {sum, num};
    } 

    int averageOfSubtree(TreeNode* root) {
        res = 0;
        dfs(root);
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

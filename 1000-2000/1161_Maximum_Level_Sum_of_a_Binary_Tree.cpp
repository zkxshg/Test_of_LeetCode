// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
// DFS

class Solution {
public:
    unordered_map<int, int> lvSum;
    int deep;

    void dfs(TreeNode* node, int depth) {
        deep = max(deep, depth);

        lvSum[depth] += node->val;

        if (node->left) dfs(node->left, depth + 1);
        if (node->right) dfs(node->right, depth + 1);
    }

    int maxLevelSum(TreeNode* root) {
        lvSum.clear(); deep = 0;
        dfs(root, 1);    

        int maxS = INT_MIN, maxL = 0;

        for (int i = 1; i <= deep; i++) {
            if (lvSum[i] > maxS) {
                maxS = lvSum[i]; maxL = i;
            }
        }

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
        return maxL;
    }
};

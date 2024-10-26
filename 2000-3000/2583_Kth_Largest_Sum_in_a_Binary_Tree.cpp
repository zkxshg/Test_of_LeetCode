// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/?envType=daily-question&envId=2024-10-22
// Binary Tree + BFS

class Solution {
public:  
    #define ll long long

    vector<ll> lvSum;

    void dfs(TreeNode* node, int lv) {
        while (lvSum.size() <= lv) {
            lvSum.push_back(0);
        }

        lvSum[lv] += node->val;

        if (node->left) dfs(node->left, lv + 1);
        if (node->right) dfs(node->right, lv + 1);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        lvSum.clear();

        dfs(root, 0);

        if (lvSum.size() < k) return -1;

        sort(lvSum.begin(), lvSum.end());

        return lvSum[lvSum.size() - k];
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

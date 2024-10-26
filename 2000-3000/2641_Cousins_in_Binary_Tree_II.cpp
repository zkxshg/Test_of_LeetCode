// https://leetcode.com/problems/cousins-in-binary-tree-ii/?envType=daily-question&envId=2024-10-23
// Breadth-First Search + Binary Tree

class Solution {
public:
    #define ll long long

    vector<ll> lvSum;

    void dfsSum(TreeNode* node, int lv) {
        while (lvSum.size() <= lv) {
            lvSum.push_back(0);
        }

        lvSum[lv] += node->val;

        if (node->left) dfsSum(node->left, lv + 1);
        if (node->right) dfsSum(node->right, lv + 1);
    }

    void dfsRep(TreeNode* node, int lv) {
        if (!node->left && !node->right) return;

        int cousinVal = 0;
        if (node->left) cousinVal += node->left->val;
        if (node->right) cousinVal += node->right->val;

        if (node->left) {
            node->left->val = lvSum[lv + 1] - cousinVal;
            dfsRep(node->left, lv + 1);
        }
        if (node->right) {
            node->right->val = lvSum[lv + 1] - cousinVal;
            dfsRep(node->right, lv + 1);
        }
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        lvSum.clear();

        dfsSum(root, 0);

        root->val = 0;
        dfsRep(root, 0);

        return root;
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

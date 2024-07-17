// https://leetcode.com/problems/delete-nodes-and-return-forest/?envType=daily-question&envId=2024-07-17
// binary tree + DFS

class Solution {
public:
    unordered_map<int, int> delT;
    vector<TreeNode*> resT;

    void dfs(TreeNode* root, bool ifRoot, bool ifDel) {
        if (root->left) {
             if (delT.find(root->left->val) != delT.end()) {
                dfs(root->left, ifDel, true);
                root->left = nullptr;
            }
            else {
                dfs(root->left, ifDel, false);
                if (ifDel) root->left = nullptr;
            }
        }

        if (root->right) {
            if (delT.find(root->right->val) != delT.end()) {
                dfs(root->right, ifDel, true);
                root->right = nullptr;
            }
            else {
                dfs(root->right, ifDel, false);
                if (ifDel) root->right = nullptr;
            }
        }

        if (ifRoot && !ifDel) resT.push_back(root);
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        delT.clear(); resT.clear();
        for (int del : to_delete) delT[del]++;

        bool ifDel = (delT[root->val]) ? true : false;
        dfs(root, true, ifDel);

        return resT;
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

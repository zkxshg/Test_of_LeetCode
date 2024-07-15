// https://leetcode.com/problems/create-binary-tree-from-descriptions/?envType=daily-question&envId=2024-07-15
// Binary tree + Union Find

class Solution {
public:
    unordered_map<int, int> U;
    
    int find(int a) {
        if (!U.count(a)) return U[a] = a;
        if (U[a] == a) return a;
        return U[a] = find(U[a]);
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        U.clear();
        unordered_map<int, TreeNode*> nodes;

        int asc = descriptions[0][0];
        for (auto& desc : descriptions) {
            int p = desc[0], c = desc[1], l = desc[2];

            if (!nodes[p]) nodes[p] = new TreeNode(p);
            if (!nodes[c]) nodes[c] = new TreeNode(c);

            if (l) nodes[p]->left = nodes[c];
            else nodes[p]->right = nodes[c];

            int pp = find(p), pc = find(c);
            U[pc] = pp;
        }
        
        return nodes[find(asc)];
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

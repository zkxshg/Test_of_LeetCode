// https://leetcode.com/problems/sum-root-to-leaf-numbers
// DFS
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        if (!(root->left) && !(root->right)) return root->val; 
        vector<string> result;   
        string temp = to_string(root->val);
        if (root->left) sumTree(root->left, &result, temp);
        if (root->right) sumTree(root->right, &result, temp);
        int sumN = 0;
        for (auto num : result) sumN += atoi(num.c_str());
        return sumN;
    }
    void sumTree(TreeNode* root, vector<string> * res, string tem){
        tem += to_string(root->val);
        if (!(root->left) && !(root->right)) res->push_back(tem);
        else {
            if (root->left) sumTree(root->left, res, tem);
            if (root->right) sumTree(root->right, res, tem);
        }
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

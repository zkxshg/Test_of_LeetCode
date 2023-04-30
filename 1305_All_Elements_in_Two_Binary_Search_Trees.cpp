// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/submissions/
// merge sort
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nodeVal;
        if (root1) recTree(root1, nodeVal);
        if (root2) recTree(root2, nodeVal);
        sort(nodeVal.begin(), nodeVal.end());
        return nodeVal;
    }    
    void recTree(TreeNode* root, vector<int> & nodeVal) {
        nodeVal.push_back(root->val);
        if (root->left) recTree(root->left, nodeVal);
        if (root->right) recTree(root->right, nodeVal);
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

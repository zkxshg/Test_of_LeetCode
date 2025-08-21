// https://leetcode.com/problems/minimum-absolute-difference-in-bst/
// dfs

class Solution {
public:
    vector<int> arr;
    
    void addNode(TreeNode* root) {
        arr.push_back(root->val);
        if (root->left ) addNode(root->left);
        if (root->right) addNode(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        arr.clear();
        addNode(root);
        sort(arr.begin(), arr.end());
        int res = INT_MAX;
        for (int i = 0; i < arr.size() - 1; i++) res = min(res, abs(arr[i] - arr[i + 1]));
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

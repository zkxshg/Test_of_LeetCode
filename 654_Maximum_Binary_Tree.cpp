// https://leetcode.com/problems/maximum-binary-tree/
// divide-and-conquer + tree

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
class Solution {
public:
    TreeNode* divide(vector<int>& nums, int st, int en) {
        int maxPos = max_element(nums.begin() + st, nums.begin() + en) - nums.begin();
        
        TreeNode* root = new TreeNode(nums[maxPos]);
        
        if (st < maxPos) root->left = divide(nums, st, maxPos);
        if (en > maxPos + 1) root->right = divide(nums, maxPos + 1, en);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = divide(nums, 0, nums.size());
        return root;
    }
};

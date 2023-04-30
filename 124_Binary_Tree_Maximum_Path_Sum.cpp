// https://leetcode.com/problems/binary-tree-maximum-path-sum
// Binary tree + DFS
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        if (!(root->left) && !(root->right)) return root->val;
        int maxv = INT_MIN;
        int result = sumTree(root, &maxv);
        return maxv;
    }
    
    int sumTree(TreeNode* root, int* maxv) {
        if (!(root->left) && !(root->right)){
            if (root->val > *maxv) *maxv = root->val;
            return root->val;
        }
        int leftmax = -88888, rightmax = -88888;
        if (root->left) leftmax = sumTree(root->left, maxv);
        if (root->right) rightmax = sumTree(root->right, maxv);
        int glo_max = max({leftmax + root->val, rightmax + root->val, root->val});
        int localmax = max({leftmax, rightmax, rightmax + leftmax + root->val, glo_max});
        if (localmax > *maxv) *maxv = localmax;
        return glo_max;
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

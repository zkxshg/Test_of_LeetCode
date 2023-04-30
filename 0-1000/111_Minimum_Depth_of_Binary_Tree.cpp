// https://leetcode.com/problems/minimum-depth-of-binary-tree
// similar to 104. Maximum Depth of Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!(root->left) && !(root->right)) return 1;
        return calDep(root, 1);
    }
    int calDep(TreeNode* root, int dep){
        if (!(root->left) && !(root->right)) return dep;
        else if (!(root->left)) return calDep(root->right, dep+1);
        else if (!(root->right)) return calDep(root->left, dep+1);
        
        int leftD = calDep(root->left, dep+1);
        int rightD = calDep(root->right, dep+1);
        if (leftD < rightD) return leftD;
        return rightD;
    }
};

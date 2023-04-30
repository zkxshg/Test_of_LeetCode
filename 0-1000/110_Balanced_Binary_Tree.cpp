// https://leetcode.com/problems/balanced-binary-tree/
// Use -1 as index to rec if Balance
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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (!(root->left) && !(root->right)) return true;
        int ifBal = calDep(root, 1);
        if (ifBal == -1) return false;
        return true;
    }
    int calDep(TreeNode* root, int dep){
        int depth = 0;
        if (!(root->left) && !(root->right)) return dep;
        else if (!(root->left)) {
            depth = calDep(root->right, dep+1);
            if (depth == -1) return -1;
            else if (depth - dep > 1) return -1;
        }
        else if (!(root->right)) {
            depth = calDep(root->left, dep+1);
            if (depth == -1) return -1;
            else if (depth - dep > 1) return -1;
        }
        else{
            int leftD = calDep(root->left, dep+1);
            if (leftD == -1) return -1;
            int rightD = calDep(root->right, dep+1);
            if (rightD == -1) return -1;
            if (abs(rightD - leftD) > 1) return -1;
            if (leftD > rightD) return leftD;
            else return rightD;
        }
        return depth;
    }
};

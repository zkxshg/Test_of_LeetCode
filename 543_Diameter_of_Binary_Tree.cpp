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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        if (!(root->left) && !(root->right)) return 0;
        int maxv = INT_MIN;
        int result = calDep(root, &maxv);
        if (result > maxv) maxv = result; 
        return maxv - 1;
    }
     int calDep(TreeNode* root, int *maxv){
        int depth = 1;
        if (!(root->left) && !(root->right)) return depth;
        else if (!(root->left)) return calDep(root->right, maxv) + 1;
        else if (!(root->right)) return calDep(root->left, maxv) + 1;
        else{
            int leftD = calDep(root->left, maxv);
            int rightD = calDep(root->right, maxv);
            int tempD = leftD + rightD + 1;
            if (tempD > *maxv) *maxv = tempD;
            if (leftD > rightD) return leftD + 1;
            else return rightD + 1;
        }
        return depth;
    }
};

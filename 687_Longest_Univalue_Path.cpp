// 4 Case : 
// 1.node == left && node != right;
// 2.node == right && node != left;
// 3.node == left && node == right;
// 4.node != left && node != right;
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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        if (!(root->left) && !(root->right)) return 0;
        
        int leftVal = 0;
        int rightVal = 0;
        
        if (root->left) {
            leftVal = longestUnivaluePath(root->left);
            if (root->val == root->left->val) {
                int leftOne = sumOne(root->left) + 1;
                if (leftOne > leftVal) leftVal = leftOne;
            }
        }
        
        if (root->right) {
            rightVal = longestUnivaluePath(root->right);
            if (root->val == root->right->val) {
                int rightOne = sumOne(root->right) + 1;
                if (rightOne > rightVal) rightVal = rightOne;
            }
        }
        
        if(root->left && root->right){
            if (root->left->val == root->right->val && root->left->val == root->val){
                int twoDirect = 2;
                twoDirect += sumOne(root->left);
                twoDirect += sumOne(root->right);
                if (twoDirect >= leftVal && twoDirect >= rightVal) return twoDirect;
            }
        }
        
        if (leftVal >= rightVal) return leftVal;
        return rightVal;
    }
    int sumOne(TreeNode* root){
        if (!(root->left) && !(root->right)) return 0;
        
        int leftVal = 0;
        if (root->left) {
            if (root->val == root->left->val) {
                leftVal = sumOne(root->left);
                leftVal += 1;
            } 
        }
        int rightVal = 0;
        if (root->right) {
            if (root->val == root->right->val) {
                rightVal = sumOne(root->right);
                rightVal += 1;
            } 
        }

        if (leftVal >= rightVal) return leftVal;
        return rightVal;
    }
};

// Search root -> search L -> search R
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (L == R) return L+R;
        // 1.Search root
        TreeNode* pos = root;
        while(pos){
            if (pos->val >= L && pos->val <= R) break;
            else if (pos->val < L) pos = pos->right;
            else pos = pos->left;
        }
        root = pos;
        int sum = 0;
        if (pos->val > L && pos->val < R) sum += pos->val;
        // 2.Search L
        if (pos->val == L) sum += pos->val;
        else{
            pos = pos->left;
            while(pos != NULL){
                if (pos->val == L) {
                    sum += pos->val;
                    if (pos->right) sum += sumAll(pos->right);
                    break;
                }
                else if (pos->val > L){
                    sum += pos->val;
                    if (pos->right) sum += sumAll(pos->right);
                    pos = pos->left;
                }
                else pos = pos->right;
            }     
        } 
        // 3.Search R
        pos = root;
        if (pos->val == R) sum += pos->val;
        else{
            pos = pos->right;
            while(pos != NULL){
                if (pos->val == R) {
                    sum += pos->val;
                    if (pos->left) sum += sumAll(pos->left);
                    break;
                }
                else if (pos->val < R){
                    sum += pos->val;
                    if (pos->left) sum += sumAll(pos->left);
                    pos = pos->right;
                }
                else pos = pos->left;
            }     
        }
        return sum;
    }
    
    int sumAll(TreeNode* root){
        int sum = root->val;
        if (root->right) sum += sumAll(root->right);
        if (root->left) sum += sumAll(root->left);
        return sum;
    }
};

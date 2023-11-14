// https://leetcode.com/problems/same-tree/
// 深度優先搜索
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q){
            if (p || q) return false;
            else return true;
        }
        
        if (p->val != q->val) return false;
        
        int isSame = true;
        if (p->left || q->left){
            if (!(p->left) || !(q->left)) return false;
            else isSame = isSameTree(p->left, q->left);
            if(isSame == false) return false;
        }
        
        if (p->right || q->right){
            if (!(p->right) || !(q->right)) return false;
            else isSame = isSameTree(p->right, q->right);
            if(isSame == false) return false;
        }
        
        return isSame;
    }
};

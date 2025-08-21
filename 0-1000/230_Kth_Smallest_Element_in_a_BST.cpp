// DFS
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        int temp = findK(root, k, 0, &result);
        return result;
    }
    
    int findK(TreeNode* root, int k, int temp, int * result) {
        if (!root->left && !root->right) {
            temp++;
            if (temp == k) *result = root->val;
            return temp;
        }
        
        if (root->left) temp = findK(root->left, k, temp, result);
        if (temp == k) return temp;
        
        temp++;
        if (temp == k) {
            *result = root->val;
            return temp;
        }
        
        if (root->right) temp = findK(root->right, k, temp, result);
        return temp;
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

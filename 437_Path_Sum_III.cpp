// countAll(Node) = countNode(Node) + countAll(left) + countAll(right)
// countNode(Node) = ifEql + countNode(left) + countNode(right)
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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        if (!(root->left) && !(root->right)) {
            if (root->val == sum) return 1;
            else return 0;
        }

        int result = 0;
        result = countAll(root, sum);
        return result;
    }
    
    int countAll(TreeNode* root, int sum){
        if (!(root->left) && !(root->right)){
            if (root->val == sum) return 1;
            else return 0;
        }
        int eql = 0;
        eql += countNode(root, sum, 0);
        if (root->left)  eql += countAll(root->left, sum);
        if (root->right) eql += countAll(root->right, sum);
        return eql;
    }
    
    int countNode(TreeNode* root, int sum, int enu){
        int eql = 0;
        enu += root->val;
        if (enu == sum)  eql += 1;
        if (root->left)  eql += countNode(root->left, sum, enu);
        if (root->right) eql += countNode(root->right, sum, enu);
        return eql;
    }
};

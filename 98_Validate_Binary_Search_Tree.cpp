// use vector<int> nodes(1000) to save each nodes on the path;
// the inequality of nodes can be inherited by next layer;
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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        vector<int> nodes(1000);
        int level = 0;
        return ValidBST(root, nodes, level);
    }

     bool ValidBST(TreeNode* root, vector<int> & nodes, int LV){
        if (!root) return true;
        // add root
        nodes[LV] = root->val;
        bool isValid = true;
        // test left
        if (root->left) {
            int temp = root->left->val;
            int nodeval = root->val;
            if (temp >= nodeval) return false;
            for (int i = 0; i < LV; i++){
                if (nodeval > nodes[i]) {
                    if (temp <= nodes[i]) return false;
                }
                else if(temp >= nodes[i]) return false;
            }
            isValid = ValidBST(root->left, nodes, LV+1);
        }
        if (!isValid) return false;
        // test right
        if (root->right) {
            int temp = root->right->val;
            int nodeval = root->val;
            if (temp <= nodeval) return false;
            for (int i = 0; i < LV; i++){
                if (nodeval > nodes[i]) {
                    if (temp <= nodes[i]) return false;
                }
                else if(temp >= nodes[i]) return false;
            }
            isValid = ValidBST(root->right, nodes, LV+1);
        }
        return isValid;
     } 
};

// reconstruct the binary tree to complete binary tree 
class Solution {
public:
    vector<long> lvLeft;
    vector<long> lvRight;
    
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        
        root->val = 1;
        lvLeft.push_back(1);
        lvRight.push_back(1);
  
        search(root, 0);
        
        int depth = min(lvLeft.size(), lvRight.size());
        long result = 1;
        for (int i = 0; i < depth; i++) {
            long wid = lvRight[i] - lvLeft[i] + 1;
            if (wid > result) result = wid;
        }
        
        return result;
    }
    
    void search(TreeNode* root, int lv) {
        if (root->right || root->left) {
            if (root->left) {
                root->left->val = (long)root->val * 2;
                
                if (lvLeft.size() < lv + 2) lvLeft.push_back(root->left->val);
                else if (lvLeft[lv + 1] > root->left->val) lvLeft[lv + 1] = root->left->val;
                
                if (lvRight.size() < lv + 2) lvRight.push_back(root->left->val);
                else if (lvRight[lv + 1] < root->left->val) lvRight[lv + 1] = root->left->val;
                
                search(root->left, lv + 1);
            }
            
            if (root->right) {
                root->right->val = (long)root->val * 2 + 1;
                
                if (lvLeft.size() < lv + 2) lvLeft.push_back(root->right->val);
                else if (lvLeft[lv + 1] > root->right->val) lvLeft[lv + 1] = root->right->val;
                
                if (lvRight.size() < lv + 2) lvRight.push_back(root->right->val);
                else if (lvRight[lv + 1] < root->right->val) lvRight[lv + 1] = root->right->val;
                
                search(root->right, lv + 1);
            }
        }
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

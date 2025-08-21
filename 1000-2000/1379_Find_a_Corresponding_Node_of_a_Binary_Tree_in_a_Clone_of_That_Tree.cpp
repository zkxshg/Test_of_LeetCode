// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
// DFS + stack
class Solution {
public:
    // true = left; false = eight;
    vector<bool> path;
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == target) return cloned;
        path.clear();
        
        bool b = search(original, target);
        
        TreeNode* res = cloned;
        while (!path.empty()) {
            if (path.back()) res = res->left;
            else res = res->right;
            
            path.pop_back();
        }
        
        return res;   
    }
    
    bool search(TreeNode* root, TreeNode* t) {
        if (root == t) return true;
        
        if (root->left) {
            if (search(root->left, t)) {
                path.push_back(true); return true;
            }
        }
        
        if (root->right) {
            if (search(root->right, t)) {
                path.push_back(false); return true;
            }
        }
        
        return false;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

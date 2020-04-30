// binary tree + DFS
class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if (!root) return false;
        bool result = ifValid(root, arr, 0);
        return result;  
    }
    
    bool ifValid(TreeNode* root, vector<int>& arr, int lv){
        if (root->val != arr[lv]) return false;
        else if (lv == arr.size() - 1) {
            if (!(root->left) && !(root->right)) return true;
            else return false;
        } 
        else if (!(root->left) && !(root->right)) return false;
        
        if (root->left) {
            if (ifValid(root->left, arr, lv + 1)) return true;
        }
        if (root->right) {
            if (ifValid(root->right, arr, lv + 1)) return true;
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

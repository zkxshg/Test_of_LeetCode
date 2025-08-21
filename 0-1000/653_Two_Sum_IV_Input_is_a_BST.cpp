// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// dfs + hash table

class Solution {
public:
    unordered_map<int, int> fre;
    bool get;
    
    void dfs(TreeNode* root, int k) {
        int v = root->val;
        
        fre[v]++;
        
        if (k - v == v) {
            if (fre[v] > 1) {
                get = true;
                return;
            }
        }
        else if (fre[k - v]) {
            get = true;
            return;
        }
        
        if (!get) {
            if (root->left) dfs(root->left, k);
            if (root->right) dfs(root->right, k);
        }
    }
    
    bool findTarget(TreeNode* root, int k) {
        fre.clear(); get = false;
        dfs(root, k);
        return get;
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

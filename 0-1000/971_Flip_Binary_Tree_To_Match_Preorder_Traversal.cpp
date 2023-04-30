// https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/
// DFS
class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if (voyage.size() < 2) return {};
        if (root->val != voyage[0]) return {-1};
        
        
        vector<int> res;
        reverse(voyage.begin(), voyage.end());
        
        bool ifMatch = ifM(root, voyage, res);
        
        if (!ifMatch || !voyage.empty()) return {-1};
        
        return res;
    }
    
    bool ifM(TreeNode* r, vector<int>& v, vector<int>& res) {
        if (!r) return true;
        
        if (r->val == v.back()) v.pop_back();
        else return false;
        
        if (r->left && r->left->val != v.back()) {
            res.push_back(r->val);
            return ifM(r->right, v, res) && ifM(r->left, v, res);
        }
        
        return ifM(r->left, v, res) && ifM(r->right, v, res);
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

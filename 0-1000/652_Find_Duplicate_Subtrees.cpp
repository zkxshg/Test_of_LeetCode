// https://leetcode.com/problems/find-duplicate-subtrees/
// DFS + Traversal + hash table

class Solution {
public:
    unordered_map<string, vector<TreeNode*>> dict;
    
    string Inorder(TreeNode* root) {
        string node = "";
        
        if (root->left) {
            node = Inorder(root->left) + node; node += 'L';
        }
        node += to_string(root->val); node += 'N';
        if (root->right) {
            node += Inorder(root->right); node += 'R';
        }
        
        dict[node].push_back(root);
        
        return node;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string path = Inorder(root);
        
        vector<TreeNode*> res;
        for (auto& p : dict)
            if (p.second.size() > 1) res.push_back(p.second[0]);
        return res;
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

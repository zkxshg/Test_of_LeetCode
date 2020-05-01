// DFS
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        string temp = to_string(root->val);
        if (!(root->left) && !(root->right)) {
            result.push_back(temp);
            return result;
        }
        if (root->left) sumTree(root->left, &result, temp);
        if (root->right) sumTree(root->right, &result, temp);
        return result;
    }
    
    void sumTree(TreeNode* root, vector<string> * res, string tem){
        tem += "->";
        tem += to_string(root->val);
        if (!(root->left) && !(root->right)) res->push_back(tem);
        else {
            if (root->left) sumTree(root->left, res, tem);
            if (root->right) sumTree(root->right, res, tem);
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

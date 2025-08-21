// https://leetcode.com/problems/trim-a-binary-search-tree/
// DFS
TreeNode* trimBST(TreeNode* root, int low, int high) {
    if(!root) return nullptr;

    if(root->val < low) {
        return trimBST(root->right, low, high);
    } else if (root->val > high) {
        return trimBST(root->left, low, high);
    }

    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);

    return root;
}

// BFS
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
class Solution {
public:
    int l, h;
    
    TreeNode* lmost(TreeNode* root) {
         // cout << "lmost: " << root->val << endl;
        
        if (!root->right) return root;
        return lmost(root->right);
    }
    
    TreeNode* deleteNode(TreeNode* root) {
        // cout << "delete: " << root->val << endl;
        
        if (!root->left && !root->right) {
            // leaf node
            return NULL;
        }
        else if (!root->left || !root->right) {
            // One Child
            if (root->left) {
                root->val = root->left->val;
                root->right = root->left->right;
                root->left = root->left->left;
            }
            else {
                root->val = root->right->val;
                root->left = root->right->left;
                root->right = root->right->right;
            }    
        }
        else {
            // Both childs
            TreeNode* lm = lmost(root->left);  
            root->val = lm->val;
            
            lm = deleteNode(lm);
        }
        
        return root;
    }
    
    void dfs(TreeNode* root) {
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);
        
        // cout << "dfs: " << root->val << endl;
        if (root->val < l || root->val > h) {
            // cout << "Need to delete: " << root->val << endl;
            root = deleteNode(root);
        }
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        l = low; h = high;
        dfs(root);
        return root;
    }
};

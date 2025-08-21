// DFS
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return root;
        
        vector<int> vals;
        addVal(&vals, root);
        sort(vals.begin(), vals.end());
        
        TreeNode* root2 = new TreeNode(vals[0]);
        TreeNode* nexR = root2;
        
        for (int i = 1; i < vals.size(); i++) {
            TreeNode* temp = new TreeNode(vals[i]);
            nexR->right = temp;
            nexR = temp;
        }
        
        return root2;
    }
    
    void addVal(vector<int>* vals, TreeNode* root) {
        vals->push_back(root->val);
        if (root->left) addVal(vals, root->left);
        if (root->right) addVal(vals, root->right);
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

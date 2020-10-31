// LUR scan -> sort -> swap outliers
class Solution {
public:
    vector<int> rootVal;
    unordered_map<int, TreeNode*> val2node;
    
    void recoverTree(TreeNode* root) {
        rootVal.clear();
        val2node.clear();
        
        LUR(root);
        
        int len = rootVal.size();  
        vector<int> sortTree(len);
        for (int i = 0; i < len; i++) sortTree[i] = rootVal[i];
        sort(sortTree.begin(), sortTree.end());
        
        vector<int> outer;
        
        int outN = 0;
        for (int i = 0; i < len; i++) {
            if (sortTree[i] != rootVal[i]) {
                outer.push_back(rootVal[i]);
                outN++;
                if (outN >= 2) break;
            }
        }
        
        TreeNode* out1 = val2node[outer[0]];
        TreeNode* out2 = val2node[outer[1]];
        
        int temV = out1->val;
        out1->val = out2->val; out2->val = temV; 
        
    }
    
    void LUR(TreeNode * root) {
        val2node[root->val] = root;
        
        if (root->left) LUR(root->left); 
        rootVal.push_back(root->val);
        if (root->right) LUR(root->right); 
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

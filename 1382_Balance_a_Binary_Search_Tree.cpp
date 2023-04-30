// https://leetcode.com/problems/balance-a-binary-search-tree/
// Binary Search

class Solution {
public:
    vector<int> vSet;
    
    void add(TreeNode* root) {
        vSet.push_back(root->val);
        
        if (root->left) add(root->left);
        if (root->right) add(root->right);
    } 
    
    void insert(int st, int en, TreeNode* root) {
        int mid = (st + en) / 2;
        
        root->val = vSet[mid];
        
        if (st < mid) {
            TreeNode* ln = new TreeNode(0); root->left = ln;
            insert(st, mid - 1, ln);
        }
        
        if (en > mid) {
            TreeNode* rn = new TreeNode(0); root->right = rn;
            insert(mid + 1, en, rn);
        }
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vSet.clear();
        
        add(root);
        
        sort(vSet.begin(), vSet.end());
        
        TreeNode* nRoot = new TreeNode(0);
        
        int n = vSet.size();
        insert(0, n - 1, nRoot);
        
        return nRoot;
    }
};

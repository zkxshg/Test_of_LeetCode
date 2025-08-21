// https://leetcode.com/problems/unique-binary-search-trees-ii/
// permutation + BST + traversal + hash map

class Solution {
public:
    int preorderTraversal(TreeNode* root) {
        if(!root) return 0;
        
        vector<int> result;
        recSearch(root, result);
        
        int res = 0;
        for (int i : result) res = res * 10 + i;
        return res;
    }
    
    void recSearch(TreeNode* root, vector<int> & result){
        if (root){
            result.push_back(root->val);
            if (root->left) recSearch(root->left, result);
            if (root->right) recSearch(root->right, result);
        }
    }
    
    
    TreeNode* buildBST(vector<int> arr) {
        TreeNode* root = new TreeNode(arr[0]);
        
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int v = arr[i];
            TreeNode* tem = root;
            
            bool ins = false;
            while (!ins) {
                if (v < tem->val) {
                    if (!tem->left) {
                        tem->left = new TreeNode(v); ins = true;
                    }
                    else tem = tem->left;
                }
                else {
                    if (!tem->right) {
                        tem->right = new TreeNode(v); ins = true;
                    }
                    else tem = tem->right;
                }
            }
        }
        
        return root;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<int> per(n);
        for (int i = 0; i < n; i++) per[i] = i + 1;
        
        unordered_map<int, int> fre;
        
        vector<TreeNode* > res;
        
        int num = 1;
        for (int i = 1; i <= n; i++) num *= i;
        
        for (int i = 0; i < num; i++) {
            TreeNode* root = buildBST(per);
            
            int order = preorderTraversal(root);
            
            if (!fre[order]) {
                res.push_back(root);
                fre[order]++;
            }

            next_permutation(per.begin(), per.end());
        }
        
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

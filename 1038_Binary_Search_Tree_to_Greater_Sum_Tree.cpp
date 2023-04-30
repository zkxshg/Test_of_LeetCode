// 1038. Binary Search Tree to Greater Sum Tree
// sort + hash table
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;
        if (!root->left && !root->right) return root;
        
        vector<int> nodeVal;
        recTree(root, nodeVal);
        
        sort(nodeVal.begin(), nodeVal.end());
        int nums = nodeVal.size();
        
        unordered_map<int, int> ind;
        for (int i = 0; i < nums; i++) ind[nodeVal[i]] = i;
        
        vector<int> sumVal(nums);
        sumVal[nums - 1] = nodeVal[nums - 1];
        for (int i = nums - 2; i >= 0; i--) sumVal[i] = nodeVal[i] + sumVal[i + 1];
        
        convNode(root, nodeVal, sumVal, ind);
        return root;
          
    }
    
    void recTree(TreeNode* root, vector<int> & nodeVal) {
        nodeVal.push_back(root->val);
        if (root->left) recTree(root->left, nodeVal);
        if (root->right) recTree(root->right, nodeVal);
    }
    
    void convNode(TreeNode* root, vector<int> & nodeVal, vector<int> & sumVal, unordered_map<int, int>& ind) {
        root->val = sumVal[ind[root->val]];
        
        if (root->left) convNode(root->left, nodeVal, sumVal, ind);
        if (root->right) convNode(root->right, nodeVal, sumVal, ind);
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

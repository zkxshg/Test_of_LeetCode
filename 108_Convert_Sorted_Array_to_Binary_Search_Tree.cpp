// binary DFS
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return NULL;
        TreeNode * node = new TreeNode(-1);
        if (len == 1) {
            node->val = nums[0];
            return node;
        }
        int mid = (len - 1) / 2;
        node->val = nums[mid];
        if (mid > 0) insertNode(node, 0, mid - 1, nums);
        if (mid < len - 1) insertNode(node, mid + 1, len - 1, nums);
        return node;    
    }
    void insertNode(TreeNode* node, int start, int end, vector<int>& nums) {
        if (start == end) insertTree(node, nums[start]);
        else {
            int mid = (start + end) / 2;
            insertTree(node, nums[mid]);
            if (mid > start) insertNode(node, start, mid - 1, nums);
            if (mid < end) insertNode(node, mid + 1, end, nums);
        }
    }
    
    void insertTree(TreeNode* node, int value) {
        if (value > node->val) {
            if (!node->right) {
                TreeNode * noderight = new TreeNode(value);
                node->right = noderight;
            }
            else insertTree(node->right, value);
        } 
        else {
            if (!node->left) {
                TreeNode * nodeleft = new TreeNode(value);
                node->left = nodeleft;
            }
            else insertTree(node->left, value);
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

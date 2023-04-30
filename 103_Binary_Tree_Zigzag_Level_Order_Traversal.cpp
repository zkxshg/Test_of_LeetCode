// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// BFS + stack
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        vector<int> lay1(1, root->val);
        result.push_back(lay1);
        if (!root->left && !root->right) return result;
        
        vector<TreeNode*> stack;
        stack.push_back(root);
        
        int depth = 1;
        while (result.size() == depth) {
            vector<int> lay;
            vector<TreeNode*> temp;
            
            if (depth % 2 == 1) {
                while (!stack.empty()) {
                    if (stack.back()->right) {
                        temp.push_back(stack.back()->right);
                        lay.push_back(stack.back()->right->val);
                    }
                    if (stack.back()->left) {
                        temp.push_back(stack.back()->left);
                        lay.push_back(stack.back()->left->val);
                    }
                    stack.pop_back();
                }
            } else {
                while (!stack.empty()) {
                    if (stack.back()->left) {
                        temp.push_back(stack.back()->left);
                        lay.push_back(stack.back()->left->val);
                    }
                    if (stack.back()->right) {
                        temp.push_back(stack.back()->right);
                        lay.push_back(stack.back()->right->val);
                    }
                    stack.pop_back();
                }
            }
            
            stack = temp;
            if (lay.size() > 0) result.push_back(lay);
            depth++;   
        }
        
        return result;
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

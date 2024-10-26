// https://leetcode.com/problems/flip-equivalent-binary-trees/?envType=daily-question&envId=2024-10-24
// Depth-First Search + Binary Tree

class Solution {
public:
    int childNum(TreeNode* root) {
        int cnum = 0;
        if (root->left) cnum++;
        if (root->right) cnum++;
        return cnum;
    }

    bool dfs(TreeNode* r1, TreeNode* r2) {
        //cout << r1->val << ":" << r2->val << endl;
        if (r1->val != r2->val) return false;

        int c1 = childNum(r1), c2 = childNum(r2);
        if (c1 != c2) return false;

        if (c1 == 0) return true;

        if (c1 == 1) {
            if (r1->left) {
                if (r2->left) return dfs(r1->left, r2->left);
                else return dfs(r1->left, r2->right);
            }
            else {
                if (r2->left) return dfs(r1->right, r2->left);
                else return dfs(r1->right, r2->right);
            }
        }

        // c1 == 2
        if (r1->left->val == r2->left->val) {
            return  (dfs(r1->left, r2->left) & dfs(r1->right, r2->right));
        }
        else if (r1->left->val == r2->right->val) {
            return (dfs(r1->left, r2->right) & dfs(r1->right, r2->left));
        }

        return false;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 || !root2) {
            if (!root1 && !root2) return true;
            return false;
        }

        return dfs(root1, root2);
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

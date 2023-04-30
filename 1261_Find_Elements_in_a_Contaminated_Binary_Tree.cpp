// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
// FindElements: recov recursively -> find: cal layer of target -> levFind: cal aver, decide goto left / right
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    TreeNode* CBT;
    FindElements(TreeNode* root) {
        CBT = root;
        CBT->val = 0;
        recov(CBT);     
    }
    
    bool find(int target) {
        int n = 0;
        int layer = 0;
        while (target > n) {
            layer++;
            n += pow(2, layer);
        }
        if (layer == 0) return true;
        return levFind(CBT, 0, layer, target, n - pow(2, layer) + 1, n);  
    }
    
    bool levFind(TreeNode* root, int nowlv, int aimlv, int target, int lval, int rval) {
        if (nowlv == aimlv) {
            if (root->val == target) return true;
            else return false;
        }
        
        int aver = lval / 2 + rval / 2;
        // In left subtree
        if (target <= aver) {
            if (!root->left) return false;
            return levFind(root->left, nowlv + 1, aimlv, target, lval, aver);
        }
        else {
            if (!root->right) return false;
            return levFind(root->right, nowlv + 1, aimlv, target, aver + 1, rval);
        }
        return false;
    }
    
    void recov(TreeNode* root) {
        int rootv = root->val;
        if (root->left) {
            root->left->val = rootv * 2 + 1;
            recov(root->left);
        }
        if (root->right) {
            root->right->val = rootv * 2 + 2;
            recov(root->right);
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

// two-step DFS: if same node -> if same tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        else if (!t) return true;
        bool result = searchRoot(s, t);
        return result;  
    }
    bool searchRoot(TreeNode* s, TreeNode* t){
        bool sameTree = false;
        // check node
        if (s->val == t->val) sameTree = ifSame(s, t);
        // or search branch
        if (!sameTree) {
            if (s->left) sameTree = searchRoot(s->left, t);
            // search right
            if (sameTree) return true;
            else if (s->right) sameTree = searchRoot(s->right, t);
        }
        return sameTree;
    }
    
    bool ifSame(TreeNode* s, TreeNode* t){
        bool SameTree = true;
        // check root
        if (s->val != t->val) return false;
        // check left
        if (s->left && t->left) SameTree = ifSame(s->left, t->left);
        else if (s->left || t->left) return false;
        // stop early
        if(!SameTree) return false;
        // check right
        if (s->right && t->right) SameTree = ifSame(s->right, t->right);
        else if (s->right || t->right) return false;
        return SameTree;
    }
};

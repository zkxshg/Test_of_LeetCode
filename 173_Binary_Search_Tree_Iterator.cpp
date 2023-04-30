// array to record

class BSTIterator {
public:
    TreeNode* node;
    vector<int> travTree;
    int pos;
    
    BSTIterator(TreeNode* root) {
        node = root;
        travTree.clear();
        pos = 0;
        
        travNode(node);
    }
    
    void travNode(TreeNode* root) {
        if (root->left) travNode(root->left);
        travTree.push_back(root->val);
        if (root->right) travNode(root->right);
    }
    
    int next() {
        pos++;
        return travTree[pos - 1];
    }
    
    bool hasNext() {
        if (pos < travTree.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
 
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

// same to 590_N-ary_Tree_Postorder_Traversal
// Preorder: root->nodes
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        if(!root) return result;
        recSearch(root, result);
        return result;
    }
    void recSearch(Node* root, vector<int> & result){
        if (root){
            int len = root->children.size();
            result.push_back(root->val);
            for (int i = 0; i < len; i++) recSearch(root->children[i], result);
        }
    }
};

// Rec the value iteratively
// Postorder: nodes->root
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
    vector<int> postorder(Node* root) {
        vector<int> result;
        if(!root) return result;
        recSearch(root, result);
        return result;
    }
    void recSearch(Node* root, vector<int> & result){
        if (root){
            int len = root->children.size();
            for (int i = 0; i < len; i++) recSearch(root->children[i], result);
            result.push_back(root->val);
        }
    };
};

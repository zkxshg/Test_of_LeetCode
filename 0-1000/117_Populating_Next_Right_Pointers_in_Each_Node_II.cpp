// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// BFS + stack
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        if (!root->left && !root->right) {
            root->next = NULL;
            return root;
        }
        
        vector<Node*> stack;
        stack.push_back(root);
        while (stack.size() > 0) {
            stack.back()->next = NULL; 
            for (int i = stack.size() - 2; i >= 0; i--) stack[i]->next = stack[i + 1];
            
            vector<Node*> nextSK;
            for (int i = 0; i < stack.size(); i++) {
                if (stack[i]->left) nextSK.push_back(stack[i]->left);
                if (stack[i]->right) nextSK.push_back(stack[i]->right);
            }
            stack = nextSK;
        }
        return root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

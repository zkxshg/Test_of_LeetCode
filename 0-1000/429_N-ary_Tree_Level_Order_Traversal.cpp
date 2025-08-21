// https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// BFS

class Solution {
public:
    vector<vector<int>> res;
        
    void addNode(Node* root, int lv) {
        if (res.size() < lv) res.push_back({root->val});
        else res[lv - 1].push_back(root->val);
        
        for (auto& kid : root->children) addNode(kid, lv + 1);
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        res.clear(); 
        if (!root) return {};
        addNode(root, 1);
        return res;
    }
};

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

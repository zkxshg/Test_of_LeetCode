// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// dfs

class Solution {
public:
    int dfs(Node* root, int lv) {
        int res = lv;
        for (auto& n : root->children) res = max(res, dfs(n, lv + 1));
        return res;
    }
    
    int maxDepth(Node* root) {
        if (!root) return 0;
        return dfs(root, 1);
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

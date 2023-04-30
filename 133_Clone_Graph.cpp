// https://leetcode.com/problems/clone-graph/
// BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        Node* root = new Node(node->val);
        if (node->neighbors.size() < 1) return root;
        
        unordered_map<int, int> searchSet; searchSet[root->val] = 1;
        unordered_map<int, Node*> nodeDict; nodeDict[root->val] = root;
        
        queue<Node*> Q1; Q1.push(node);
        queue<Node*> Q2; Q2.push(root);
        
        while (!Q1.empty()) {
            Node* tempN = Q1.front();
            Node* nCopy = Q2.front();
            
            for (Node* n : tempN->neighbors) {
                if (!searchSet[n->val]) {
                    Node* newN = new Node(n->val);
                    searchSet[n->val] = 1;
                    nodeDict[newN->val] = newN;
                    
                    nCopy->neighbors.push_back(newN);
                    
                    Q1.push(n);
                    Q2.push(newN);
                } 
                else nCopy->neighbors.push_back(nodeDict[n->val]);
            }
            
            Q1.pop();
            Q2.pop();
        }
        
        
        return root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

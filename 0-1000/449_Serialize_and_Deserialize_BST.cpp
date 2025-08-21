// https://leetcode.com/problems/serialize-and-deserialize-bst/
// BST 
class Codec {
public:
    
    string seriTree;
    vector<TreeNode* > nodeSet;

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        seriTree = ""; nodeSet.clear();
        if(!root) return seriTree;
        
        nodeSet.push_back(root);
        addNode(nodeSet);
        
        return seriTree;
    }
    
    void addNode(vector<TreeNode* >& nSet) {
        if (!nSet.empty()) {
            vector<TreeNode* > tempSet;
            
            for (TreeNode* node : nSet) {
                if (!node) {
                    seriTree += "N";
                    seriTree += ",";
                    continue;
                }
                
                seriTree += to_string(node->val);
                seriTree += ",";
                
                tempSet.push_back(node->left);
                tempSet.push_back(node->right);
            }
            
            nSet = tempSet;
            addNode(nSet);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = data.size(); if (len < 1) return NULL;
        
        TreeNode* root = new TreeNode(-1);
        vector<TreeNode* > nodeQ;        
        nodeQ.push_back(root);
        
        int pos = 0, nex = data.find(","), qpos = 0;
        while (pos < len) {
            string num = data.substr(pos, nex - pos);
            
            if (num == "N") {
                qpos++;
                pos = nex + 1;
                nex = data.find(",", pos);
            } else {
                int nums =  atoi(num.c_str());
                TreeNode* node = nodeQ[qpos];
                node->val = nums;

                TreeNode* nodeL = new TreeNode(-1);;
                TreeNode* nodeR = new TreeNode(-1);;
                node->left = nodeL;
                node->right = nodeR;
                nodeQ.push_back(nodeL);
                nodeQ.push_back(nodeR);

                qpos++;
                pos = nex + 1;
                nex = data.find(",", pos);         
            }
        }  
        cut(root);
        
        return root;
    }
    
    void cut(TreeNode* root) {
        if (root->left->val == -1) root->left = NULL;
        else cut(root->left);
        
        if (root->right->val == -1) root->right = NULL;
        else cut(root->right);
    }
    
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

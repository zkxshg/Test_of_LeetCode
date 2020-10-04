// Binary Tree
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root->left && !root->right) {
            if (root->val % 2 == 0) return false;
            return true;
        } 
        
        vector<TreeNode*> nodeSet;
        nodeSet.push_back(root);

        return OETree(0, nodeSet);
    }
    
    bool OETree(int lv, vector<TreeNode* > nodeSet) {
        if (lv == 0) {
            TreeNode* root = nodeSet[0];
            
            if (root->val % 2 == 0) return false;
            
            vector<TreeNode* > temp;
            if (root->right) temp.push_back(root->right);
            if (root->left) temp.push_back(root->left);
            reverse(temp.begin(), temp.end());
            
            return OETree(1, temp);
        }
        else if (lv % 2 == 1) {
            int len = nodeSet.size();
            vector<TreeNode* > temp;
            
            for (int i = 0; i < len - 1; i++) {
                if (nodeSet[i]->val % 2 != 0) return false;
                if (nodeSet[i]->val <= nodeSet[i + 1]->val) return false;
                
                if (nodeSet[i]->left) temp.push_back(nodeSet[i]->left);
                if (nodeSet[i]->right) temp.push_back(nodeSet[i]->right);
            }

            if (nodeSet[len - 1]->val % 2 != 0) return false;
            if (nodeSet[len - 1]->left) temp.push_back(nodeSet[len - 1]->left);
            if (nodeSet[len - 1]->right) temp.push_back(nodeSet[len - 1]->right);
         
            if (temp.size() == 0) return true;
            return OETree(lv + 1, temp);   
        }
        else {
            int len = nodeSet.size();
            vector<TreeNode* > temp;
            
            for (int i = len - 1; i > 0; i--) {
                if (nodeSet[i]->val % 2 == 0) return false;
                if (nodeSet[i]->val <= nodeSet[i - 1]->val) return false;
                
                if (nodeSet[i]->right) temp.push_back(nodeSet[i]->right);
                if (nodeSet[i]->left) temp.push_back(nodeSet[i]->left);
            }
            
            if (nodeSet[0]->val % 2 == 0) return false;
            if (nodeSet[0]->right) temp.push_back(nodeSet[0]->right);
            if (nodeSet[0]->left) temp.push_back(nodeSet[0]->left);
            
            if (temp.size() == 0) return true;
            
            reverse (temp.begin(), temp.end());
            return OETree(lv + 1, temp);
        }
        
        return true;
    }
};

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

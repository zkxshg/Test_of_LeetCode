// DFS search
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
    vector<int> findMode(TreeNode* root) {
        vector<int> value;
        if(!root) return value;
        value.push_back(root->val);
        vector<int> counter;
        counter.push_back(0);
        
        searchTree(root, counter, value);
        // Find the mode
        int maxIn = 0;
        int maxVal = 0;
        for (int i = 0; i < counter.size(); i++){
            if (counter[i] > maxVal) {
                maxIn = i;
                maxVal = counter[i];
            }
        }
        vector<int> result;
        result.push_back(value[maxIn]);
        // Find other modes
        for (int i = 0; i < maxIn; i++){
            if(counter[i] == maxVal) result.push_back(value[i]);
        }
        for (int i = maxIn + 1; i < counter.size(); i++){
            if(counter[i] == maxVal) result.push_back(value[i]);
        }
        return result;
    }
    
    void searchTree(TreeNode* root, vector<int> & ct, vector<int> & value){
        int index = root->val;
        // Search the value
        bool inV = false;
        for (int i = 0; i < value.size(); i++){
            if (value[i] == index) {
                ct[i]++;
                inV = true;
                break;
            }
        }
        // If no value, add it
        if (!inV){
            value.push_back(index);
            ct.push_back(1);
        }
        // DFS
        if(root->right) searchTree(root->right, ct, value);
        if(root->left) searchTree(root->left, ct, value);
    }
};

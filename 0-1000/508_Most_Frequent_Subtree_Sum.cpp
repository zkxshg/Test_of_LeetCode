// Same to 501. Find Mode in Binary Search Tree
// DFS + DP + record array
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> value;
        if(!root) return value;
        vector<int> counter;
        int sumall = searchTree(root, counter, value);
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
        for (int i = 0; i < maxIn; i++){
            if(counter[i] == maxVal) result.push_back(value[i]);
        }
        for (int i = maxIn + 1; i < counter.size(); i++){
            if(counter[i] == maxVal) result.push_back(value[i]);
        }
        return result;
    }
    
    int searchTree(TreeNode* root, vector<int> & ct, vector<int> & value){
        // calculate the sum value
        int sumTree = 0;
        sumTree += root->val; 
        if (root->right) sumTree += searchTree(root->right, ct, value);
        if (root->left) sumTree += searchTree(root->left, ct, value);
        // search or insert the sum value
        int index = sumTree;
        bool inV = false;
        for (int i = 0; i < value.size(); i++){
            if (value[i] == index) {
                ct[i]++;
                inV = true;
                break;
            }
        }
        if (!inV){
            value.push_back(index);
            ct.push_back(1);
        }
        return sumTree;
    }
};

// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/?envType=daily-question&envId=2024-07-16
// Binary Tree + DFS (3h)

class Solution {
public:
      bool findPath(TreeNode* node, int target, string& path) {
        if (node == nullptr) return false;
        
        // Check if current node is the target
        if (node->val == target) {
            return true;
        }
        
        // Recursively search in left and right
        if (node->left && findPath(node->left, target, path)) {
            path += 'L'; // Go to left child
            return true;
        }

        if (node->right && findPath(node->right, target, path)) {
            path += 'R'; // Go to right child
            return true;
        }
        
        return false;
    }
    
    // Main function to get directions from startValue to destValue
    string getDirections(TreeNode* root, int startValue, int destValue) {
        if (root == nullptr) return "";
        
        string rootToStart, rootToDest;
        
        // Find path from root to start and destination
        findPath(root, startValue, rootToStart);
        findPath(root, destValue, rootToDest);

        while (!rootToStart.empty() && !rootToDest.empty() && 
                rootToStart.back() == rootToDest.back()) {
            rootToStart.pop_back();
            rootToDest.pop_back();
        }
        // cout << rootToStart << endl;
        // cout << rootToDest << endl;
        
        // Reverse the RootToStart path to startToRoot path 
        reverse(rootToDest.begin(), rootToDest.end());
        

        string startToRoot(rootToStart.size(), 'U');

        // cout << startToRoot << "+" << rootToDest << endl;
        
        // Combine the two directions and return
        return startToRoot + rootToDest;
    }
};

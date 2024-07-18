// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/?envType=daily-question&envId=2024-07-18
// Binary tree + DFS (20min)

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        dfs(root, distance, result);
        return result;
    }

    // Returns a vector of distances to all leaf nodes from the current node
    vector<int> dfs(TreeNode* node, int distance, int& result) {
        if (!node) return {};

        // If leaf node, return {1}
        if (!node->left && !node->right) {
            return {1};
        }

        // Recursively get distances from left and right subtrees
        vector<int> leftDistances = dfs(node->left, distance, result);
        vector<int> rightDistances = dfs(node->right, distance, result);

        // Combine distances from left and right subtrees
        for (int l : leftDistances) {
            for (int r : rightDistances) {
                if (l + r <= distance) {
                    result++;
                }
            }
        }

        // Increment all distances by 1 and return
        vector<int> currentDistances;
        for (int l : leftDistances) {
            currentDistances.push_back(l + 1);
        }
        for (int r : rightDistances) {
            currentDistances.push_back(r + 1);
        }
        
        return currentDistances;
    }
};

// Merge to accelerate

class Solution {
public:
    int result;

    int countPairs(TreeNode* root, int distance) {
        result = 0;
        dfs(root, distance);
        return result;
    }

    // Returns a vector of distances to all leaf nodes from the current node
    vector<int> dfs(TreeNode* node, int distance) {
        if (!node) return {};

        // If leaf node, return {1}
        if (!node->left && !node->right) {
            return {1};
        }

        // Recursively get distances from left and right subtrees
        vector<int> leftDistances = dfs(node->left, distance);
        vector<int> rightDistances = dfs(node->right, distance);

        // Combine distances from left and right subtrees
        for (int l : leftDistances) {
            for (int r : rightDistances) {
                if (l + r <= distance) {
                    result++;
                }
                else break;
            }
        }

        // Increment all distances by 1 and return
        vector<int> currentDistances;
        int lpos = 0, rpos = 0, llen = leftDistances.size(), rlen = rightDistances.size();
        while (lpos < llen || rpos < rlen) {
            if (lpos < llen && rpos < rlen) {
                if (leftDistances[lpos] <= rightDistances[rpos]) {
                    currentDistances.push_back(leftDistances[lpos] + 1);
                    lpos++;
                }
                else {
                    currentDistances.push_back(rightDistances[rpos] + 1);
                    rpos++;
                }
            }
            else {
                if (lpos < llen) {
                    currentDistances.push_back(leftDistances[lpos] + 1);
                    lpos++;
                }
                else {
                    currentDistances.push_back(rightDistances[rpos] + 1);
                    rpos++;
                }
            }
        }
        
        return currentDistances;
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

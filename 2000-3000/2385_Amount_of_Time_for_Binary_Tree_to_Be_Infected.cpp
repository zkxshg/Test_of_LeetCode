// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
// Graph + DFS + BFS

class Solution {
public:
    unordered_map<int, vector<int>> paths;
    unordered_map<int, int> visited;
    int res = 0;

    void dfs(TreeNode* root) {
        if (root->left) {
            paths[root->val].push_back(root->left->val);
            paths[root->left->val].push_back(root->val);
            dfs(root->left);
        }
        if (root->right) {
            paths[root->val].push_back(root->right->val);
            paths[root->right->val].push_back(root->val);
            dfs(root->right);
        }
    }

    void bfs(int root){
        int dist = visited[root];

        for (int nex : paths[root]) {
            if (visited.count(nex) == 0) {
                int nex_dist = dist + 1;
                visited[nex] = nex_dist;
                res = max(res, nex_dist);

                bfs(nex);
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        paths.clear();
        dfs(root);

        visited.clear(); res = 0;
        visited[start] = 0;
        bfs(start);

        return res;        
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

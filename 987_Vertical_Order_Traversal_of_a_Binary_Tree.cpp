// DFS
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root->left && !root->right) return {{root->val}};

        vector<vector<int>> res;
        
        vector<vector<pair<int, int> > > pos(1000);
        vector<vector<pair<int, int> > > neg(1000);

        dfs(root, pos, neg, 0, 0);
 
        for (int i = -999; i < 0; i++) {
            int j = -i;
            if (!neg[j].empty()) {
                sort(neg[j].begin(), neg[j].end());
                vector<int> tem;
                for (pair<int, int> p : neg[j]) tem.push_back(p.second);
                res.push_back(tem);
            }
        }
        
        for (int j = 0; j < 1000; j++) {
            if (!pos[j].empty()) {
                sort(pos[j].begin(), pos[j].end());
                vector<int> tem;
                for (pair<int, int> p : pos[j]) tem.push_back(p.second);
                res.push_back(tem);
            }
        }
        
        return res;
    }
    
    void dfs(TreeNode* root, vector<vector<pair<int, int> > >& pos, vector<vector<pair<int, int> > >& neg, int x, int y) {     
        if (x >= 0) pos[x].push_back(make_pair(y, root->val));
        else neg[-x].push_back(make_pair(y, root->val));
        
        if (root->left) dfs(root->left, pos, neg, x - 1, y + 1);
        if (root->right) dfs(root->right, pos, neg, x + 1, y + 1);
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

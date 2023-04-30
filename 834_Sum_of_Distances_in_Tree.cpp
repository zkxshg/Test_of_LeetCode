// https://leetcode.com/problems/sum-of-distances-in-tree/
// node -> tree -> DFS + DP

class Solution {
public:
    int N;
    
    struct TreeNode {
        int val;
        int dis;
        int nums;
        vector<TreeNode* > children;
        TreeNode() : val(0), dis(0), nums(0), children() {}
        TreeNode(int x) : val(x), dis(0), nums(0), children() {}
    };
 
    void BuildTree(unordered_map<int, vector<int> >& nodeSet, unordered_map<int, int>& rec, TreeNode* root) {
        int value = root->val;
        
        for (int i : nodeSet[value]) {
            if (!rec[i]) {
                TreeNode* child = new TreeNode(i);
                root->children.push_back(child);
                rec[i]++;
            }
        }
        
        for (auto& T : root->children) BuildTree(nodeSet, rec, T);
    }
    
    pair<int, int> calDist(TreeNode* root) {
        if (root->children.empty()) return make_pair(0, 0);
        
        int num = 0, dist = 0;
        for (auto& child : root->children) {
            pair<int, int> p = calDist(child);
            num += p.first + 1;
            dist += p.second + p.first + 1;
        }
        
        root->dis = dist;
        root->nums = num;
        
        return make_pair(num, dist);
    }
    
    void calSumOfDist(TreeNode* root, int rDist, vector<int>& res) {
        int leftNum = N - root->nums - 1;
        
        res[root->val] = rDist + leftNum  - root->nums - 1;
        
        for (auto& child : root->children) calSumOfDist(child, res[root->val], res);
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // Rec the node and edge
        unordered_map<int, vector<int> > nodeSet;
        for (auto& v : edges) {
            nodeSet[v[0]].push_back(v[1]);
            nodeSet[v[1]].push_back(v[0]);
        }
        
        // Build the tree
        unordered_map<int, int> rec;
        TreeNode* root = new TreeNode(0);
        rec[0]++;
        
        BuildTree(nodeSet, rec, root);
        
        // First cal 0's dists
        pair<int, int> rootP = calDist(root);
        
        // cal other points' dist
        N = n;
        vector<int> res(n); res[0] = root->dis;
        for (auto& child : root->children) calSumOfDist(child, root->dis, res);
        
        return res;
        
    }
};

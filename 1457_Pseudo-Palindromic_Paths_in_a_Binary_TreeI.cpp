// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/submissions/
// DFS

class Solution {
public:
    int res;
    
    bool isPali(vector<int>& P) {
        int result = 0, odd = 0;
        
        for (int num : P) {
            if (num % 2 != 0) {
                if (!odd) odd++;
                else return false;
            }
        }

        return true;
    }
    
    void dfs(TreeNode* root, vector<int> path) {
        path[root->val]++;
        
        if (!root->left && !root->right) {
            if (isPali(path)) res++;  
        }
        else {
            if (root->left) dfs(root->left, path);
            if (root->right) dfs(root->right, path);
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        res = 0;
        
        vector<int> path(10);
        dfs(root, path);
        
        return res;
    }
};

// permutation -> circle
class Solution {
public:
    int res;
    
    bool testEven(vector<int>& P, int ind) {
        int n = P.size();
        
        for (int i = 0; i < n / 2; i++) {
            int pos = (ind + i + 1) % n, neg = (ind >= i) ? ind - i : ind - i + n;
            if (P[pos] != P[neg]) return false;
        }
        
        return true;
    }
    
    bool testOdd(vector<int>& P, int ind) {
        int n = P.size();
        
        for (int i = 1; i <= n / 2; i++) {
            int pos = (ind + i) % n, neg = (ind >= i ) ? ind - i : ind - i + n;
            if (P[pos] != P[neg]) return false;
        }
        
        return true;
    }
    
    bool isPali(vector<int>& P) {
        int n = P.size();
        
        if (n % 2) {
            for (int i = 0; i < n; i++) 
                if (testOdd(P, i)) return true;
        }
        else {
            for (int i = 0; i < n; i++) 
                if (testEven(P, i)) return true;
        }
        
        return false;
    }
    
    void dfs(TreeNode* root, vector<int> path) {
        path.push_back(root->val);
        
        if (!root->left && !root->right) {
            if (isPali(path)) res++;
        }
        else {
            if (root->left) dfs(root->left, path);
            if (root->right) dfs(root->right, path);
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        res = 0;
        
        vector<int> path;
        dfs(root, path);
        
        return res;
    }
};

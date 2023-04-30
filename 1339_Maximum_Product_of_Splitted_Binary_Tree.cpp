// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
// DFS

class Solution {
public:
    #define ll long long 
    ll ub = 1e9 + 7;

    ll ST;
    ll maxST;
    map<TreeNode*, ll> treeSum;

    ll qmul(ll x, ll y, ll mod) {
        ll ret = 0;
        while (y) {
            if (y & 1)
                ret = (ret + x) % mod;
            x = x * 2 % mod;
            y >>= 1;
        }
        return ret;
    }

    ll sumTree(TreeNode* root) {
        ll res = root->val;

        if (root->left) res += sumTree(root->left);
        if (root->right) res += sumTree(root->right);

        // res %= ub;
        treeSum[root] = res;

        return res;
    }

    void dfs(TreeNode* root) {
        if (root->left) {
            maxST = max(maxST, (ST - treeSum[root->left]) * treeSum[root->left]);
            dfs(root->left);
        }
        
        if (root->right) {
            maxST = max(maxST, (ST - treeSum[root->right]) * treeSum[root->right]);
            dfs(root->right);
        }
    }

    int maxProduct(TreeNode* root) {
        treeSum.clear(); maxST = 0;

        ST = sumTree(root); 

        dfs(root);

        maxST %= ub;
        return maxST;
    }
};

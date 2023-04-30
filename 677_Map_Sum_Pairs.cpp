// https://leetcode.com/problems/map-sum-pairs/
// Trie

class MapSum {
public:
    struct TreeNode {
        int val;
        unordered_map<char, TreeNode*> b2nDict;
        TreeNode(int ifEnd) : val(ifEnd), b2nDict() {}
    };
    
    TreeNode* root;
    
    MapSum() {
        root = new TreeNode(-1);
    }
    
    void insert(string key, int val) {
        TreeNode* nex = root;
        for (char c : key) {
            if (!nex->b2nDict[c]) {
                TreeNode * newN = new TreeNode(-1);
                nex->b2nDict[c] = newN;
            }
            nex = nex->b2nDict[c];
        }
        nex->val = val;
    }
    
    int sum(string prefix) {
        TreeNode* nex = root;
        for (char c : prefix) {
            if (!nex->b2nDict[c]) return 0;
            else nex = nex->b2nDict[c];
        }
        return querySum(nex);
    }
    
    int querySum(TreeNode* nex) {
        int res = 0;
        if (nex->val > 0) res += nex->val;
        for (auto& p : nex->b2nDict)
            if (p.second) res += querySum(p.second);
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

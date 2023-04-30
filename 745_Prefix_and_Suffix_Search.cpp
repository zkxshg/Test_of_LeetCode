// https://leetcode.com/problems/prefix-and-suffix-search/
// Trie + DFS

class WordFilter {
public:
    struct TreeNode {
        int index;
        unordered_map<char, TreeNode*> b2nDict;
        TreeNode(int ifEnd) : index(ifEnd), b2nDict() {}
    };
    
    TreeNode* root;
    
    TreeNode* search(string& word) {
        TreeNode * nex = root;
        
        for (char w : word) {
            if (!nex->b2nDict[w]) return NULL;
            nex = nex->b2nDict[w];
        }
        
        return nex;
    }
    
    void add(string& str, int ind) {
        if (str.size() < 1) return;
        
        TreeNode* node = root;
        
        for (char c : str) {
            if (node->b2nDict[c]) node = node->b2nDict[c];
            else {
                TreeNode* nex = new TreeNode(-1);
                node->b2nDict[c] = nex;
                node = nex;
            }
        }
        node->index = ind;
    }
    
    void dfs(TreeNode* node, set<int>& VS) {
        if (node->index >= 0) VS.insert(node->index);
        for (auto& p : node->b2nDict) dfs(p.second, VS);
    }
    
    WordFilter(vector<string>& words) {
        root = new TreeNode(-1);
        
        int len = words.size();
        for (int i = 0; i < len; i++) {
            string& w = words[i];
            
            int n = w.size();
            for (int j = 0; j <= n; j++) {
                string qw = w.substr(j) + "#" + w; // cout << qw << ",";
                add(qw, i);
            } 
        }
    }
    
    int f(string prefix, string suffix) {
        string aim = suffix + "#" + prefix;

        TreeNode* res = search(aim);
        
        if (!res) return -1;
        
        set<int> valiSet;
        dfs(res, valiSet);
        
        int lgt = -1;
        for (int i : valiSet) lgt = max(lgt, i);
        return lgt;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

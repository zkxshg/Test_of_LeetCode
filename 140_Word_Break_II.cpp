// https://leetcode.com/problems/word-break-ii/
// Trie + Backtracking

class Solution {
public:
    struct TreeNode {
        bool endP;
        unordered_map<char, TreeNode*> b2nDict;
        TreeNode(bool ifEnd) : endP(ifEnd), b2nDict() {}
    };
    
    TreeNode* root;
    vector<string> res;
    
    void add(string& str, TreeNode* node) {
        if (str.size() < 1) return;
        
        for (char c : str) {
            if (node->b2nDict[c]) node = node->b2nDict[c];
            else {
                TreeNode* nex = new TreeNode(false);
                node->b2nDict[c] = nex;
                node = nex;
            }
        }
        node->endP = true;
    }
    
    void search(string& str,  string ts, int pos, TreeNode* node) {
        if (pos >= str.size()) {
            if (node->endP) res.push_back(ts);
            return;
        }
        
        if (node->endP) search(str, ts + " ", pos, root);

        if (node->b2nDict[str[pos]]) search(str, ts + str[pos], pos + 1, node->b2nDict[str[pos]]);
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        root = new TreeNode(false);
        res.clear();
        
        for (string& w : wordDict) add(w, root);
        
        string tem = "";
        search(s, tem, 0, root);
        
        return res;
    }
    
    
};

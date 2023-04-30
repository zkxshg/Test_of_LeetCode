// https://leetcode.com/problems/concatenated-words/submissions/
// Trie + DFS

class Solution {
public:
    struct TreeNode {
        bool endP;
        unordered_map<char, TreeNode*> b2nDict;
        TreeNode(bool ifEnd) : endP(ifEnd), b2nDict() {}
    };
    
    TreeNode* root;
    
    static bool cmp(string& a, string& b) {
        return a.size() < b.size();
    }
    
    bool search(string& str, int pos, TreeNode* node) {
        if (pos >= str.size()) {
            if (node->endP) return true;
            return false;
        }
        
        if (node->endP && search(str, pos, root)) return true;

        if (node->b2nDict[str[pos]] && search(str, pos + 1, node->b2nDict[str[pos]])) return true;
        
        return false;
    }
    
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
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root = new TreeNode(false);
        
        sort(words.begin(), words.end(), cmp);
        for (auto& w : words) cout << w << ","; cout << endl;
        
        vector<string> res;

        for (auto& word : words) {
            // cout << "!:" << word << endl;
            if (search(word, 0, root)) res.push_back(word); 
            add(word, root);
        }
        
        return res;
    }
};

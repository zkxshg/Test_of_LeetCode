// https://leetcode.com/problems/implement-trie-prefix-tree/
// prefix trie
class Trie {
public:
    struct TreeNode {
        bool endP;
        unordered_map<char, TreeNode*> b2nDict;
        TreeNode(bool ifEnd) : endP(ifEnd), b2nDict() {}
    };
    
    TreeNode * root = new TreeNode(true);
    
    /** Initialize your data structure here. */
    Trie() {
        root->b2nDict.clear();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode * nex = root;
        for (char w : word) {
            if (!nex->b2nDict[w]) {
                TreeNode * newNode = new TreeNode(true);
                nex->b2nDict[w] = newNode;
                if (nex->endP) nex->endP = false;
                nex = newNode;
            } 
            else nex = nex->b2nDict[w];
        }
        TreeNode * newNode = new TreeNode(true);
        nex->b2nDict['E'] = newNode;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode * nex = root;
        for (char w : word) {
            if (!nex->b2nDict[w]) return false;
            nex = nex->b2nDict[w];
        }
        if (nex->endP || nex->b2nDict['E']) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode * nex = root;
        for (char w : prefix) {
            if (!nex->b2nDict[w]) return false;
            nex = nex->b2nDict[w];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// https://leetcode.com/problems/design-add-and-search-words-data-structure/
class WordDictionary {
public:
    /** Initialize your data structure here. */
    
    struct TreeNode {
        char val;
        unordered_map<char, TreeNode*> b2nDict;
        TreeNode(char ifEnd) : val(ifEnd), b2nDict() {}
    };
    
    TreeNode * root = new TreeNode('R');
    
    WordDictionary() {
        root->b2nDict.clear();
    }
    
    /** Adds a word into the data structure. */
    
    void addWord(string word) {
        TreeNode * nex = root;
        
        for (char w : word) {
            if (!nex->b2nDict[w]) {
                TreeNode * newNode = new TreeNode(w);
                nex->b2nDict[w] = newNode;
                nex = newNode;
            } 
            else nex = nex->b2nDict[w];
        }
        
        if (!nex->b2nDict['E']) {
            TreeNode * newNode = new TreeNode('E');
            nex->b2nDict['E'] = newNode;
        }   
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    
    bool search(string word) {
        TreeNode * nex = root;
        
        for (int w = 0; w < word.size(); w++) {
            if (word[w] == '.') return searchStar(word.substr(w, word.size() - w), nex);
            
            if (!nex->b2nDict[word[w]]) return false;
            nex = nex->b2nDict[word[w]];
        }
        if (nex->b2nDict['E']) return true;
        return false;
    }
    
    bool searchStar(string word, TreeNode * node2) {
        TreeNode * node = node2;
        
        if (!node) return false;
        
        if (word.size() == 0) {
            if (node->val == 'E') return true;
            else return false;
        } 
        
        if (word.size() >= 1 && node->val == 'E') return false;
        
        TreeNode * nex = node;
        for (int w = 0; w < word.size(); w++) {
            
            if (word[w] == '.') {
                
                for(auto nd = nex->b2nDict.begin(); nd != nex->b2nDict.end(); ++nd ) {
                    if (w >= word.size() - 1) {
                        if (nd->first != 'E') return true;
                    } 
                    else if (searchStar(word.substr(w + 1, word.size() - w - 1), nd->second)) return true;
                }
                
                return false;
            }
            
            if (!nex || !nex->b2nDict[word[w]]) return false;
            nex = nex->b2nDict[word[w]];
        }
        
        if (nex->b2nDict['E']) return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

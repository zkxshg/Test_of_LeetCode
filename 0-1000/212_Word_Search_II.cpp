// https://leetcode.com/problems/word-search-ii/
// BFS + prefix trie

class Solution {
public:
    struct TreeNode {
        bool endP;
        unordered_map<char, TreeNode*> b2nDict;
        TreeNode(bool ifEnd) : endP(ifEnd), b2nDict() {}
    };
    
    TreeNode * root = new TreeNode(true);
    
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
    
    vector<string> res;
    unordered_map<string, int> get;
    
    void wordCheck(vector<vector<char>>& board, vector<vector<bool>>& ifCheck, 
                    TreeNode* node, int x, int y, string str) {
        
        char ch = board[x][y];
        
        if (!node->b2nDict[ch]) return;
        
        node = node->b2nDict[ch];
        str += board[x][y];
        
        if  (node->endP || node->b2nDict['E']) {
            if (!get[str]) {
                res.push_back(str);
                get[str]++;
            }
        }
 
        ifCheck[x][y] = true;
        
        int len = board.size(), wid = board[0].size();
        
        if (x < len - 1 && !ifCheck[x+1][y]) 
            wordCheck(board, ifCheck, node, x + 1, y, str);
        
        if (x > 0 && !ifCheck[x-1][y]) 
            wordCheck(board, ifCheck, node, x - 1, y, str);
        
        if (y < wid - 1 && !ifCheck[x][y+1]) 
            wordCheck(board, ifCheck, node, x, y + 1, str);
        
        if (y > 0 && !ifCheck[x][y-1]) 
            wordCheck(board, ifCheck, node, x, y - 1, str);
            
        ifCheck[x][y] = false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size(), num = words.size();
        
        res.clear(); get.clear();
        
        root->b2nDict.clear();
        
        for (auto& w : words) insert(w);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<bool>> ifCheck(m, vector<bool>(n, false));
                string s = "";
                wordCheck(board, ifCheck, root, i, j, s);
            }
        }
        
        return res;
    }
};

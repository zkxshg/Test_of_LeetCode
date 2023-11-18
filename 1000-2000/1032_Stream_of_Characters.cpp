// https://leetcode.com/problems/stream-of-characters/
// reverse Trie
class StreamChecker {
public:
    struct TreeNode {
        char val;
        unordered_map<char, TreeNode*> b2nDict;
        TreeNode(char ifEnd) : val(ifEnd), b2nDict() {}
    };
    
    TreeNode * root;
    vector<TreeNode*> stream;
    int counter;
    string s;
    
    StreamChecker(vector<string>& words) {
        root =  new TreeNode('S');
        stream.clear(); stream.push_back(root);
        counter = 0;
        s = "";
        
        for (string word : words) {
            TreeNode * temp = root;
            reverse(word.begin(), word.end()); 
            for (char w : word) {
                if (temp->b2nDict[w]) temp = temp->b2nDict[w];
                else {
                    TreeNode * newNode = new TreeNode(w);
                    temp->b2nDict[w] = newNode;
                    temp = newNode;
                }
            }
            if (!temp->b2nDict['E']) {
                TreeNode * newNode = new TreeNode('E');
                temp->b2nDict['E'] = newNode;
            }
            counter++;
        }   
    }
    
    bool query(char letter) {
        s += letter;
        bool inList = false;
        
        TreeNode * temp = root;
        for (int i = s.size() - 1; i >=0; i--) {
            if (!temp->b2nDict[s[i]]) return false;
            else temp = temp->b2nDict[s[i]];
            if (temp->b2nDict['E']) return true;
        }
        return false;
    }
};

// straightforward
class StreamChecker {
public:
    struct TreeNode {
        char val;
        unordered_map<char, TreeNode*> b2nDict;
        TreeNode(char ifEnd) : val(ifEnd), b2nDict() {}
    };
    
    TreeNode * root;
    vector<TreeNode*> stream;
    int counter;
    
    StreamChecker(vector<string>& words) {
        root =  new TreeNode('S');
        stream.clear(); stream.push_back(root);
        counter = 0;
        
        for (string word : words) {
            TreeNode * temp = root;
            for (char w : word) {
                if (temp->b2nDict[w]) temp = temp->b2nDict[w];
                else {
                    TreeNode * newNode = new TreeNode(w);
                    temp->b2nDict[w] = newNode;
                    temp = newNode;
                }
            }
            if (!temp->b2nDict['E']) {
                TreeNode * newNode = new TreeNode('E');
                temp->b2nDict['E'] = newNode;
            }
            counter++;
        }   
    }
    
    bool query(char letter) {
        vector<TreeNode*> tempV;
        bool inList = false;
        
        for (TreeNode* node : stream) {
            if (node->b2nDict[letter]) {
                tempV.push_back(node->b2nDict[letter]);
                if (node->b2nDict[letter]->b2nDict['E']) inList = true;
            }
        }
        
        tempV.push_back(root);
        stream = tempV;
        return inList;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

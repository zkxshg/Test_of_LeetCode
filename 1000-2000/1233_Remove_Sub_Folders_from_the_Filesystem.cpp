// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/?envType=daily-question&envId=2024-10-25
// String + Depth-First Search + Trie

class TrieNode {
public:
    unordered_map<string, TrieNode*> children;
    bool isEnd; 
    TrieNode() : isEnd(false) {}
};

class Solution {
public:
    bool insertAndCheck(TrieNode* root, const string& path) {
        TrieNode* currentNode = root;
        bool isSubfolder = false;

        string temPath = "";
        for (int i = 1; i < path.length(); i++) { 
            char ch = path[i];

            if (ch != '/') temPath += ch;

            if (ch == '/' || i == path.length() - 1) {
                if (currentNode->children.find(temPath) == currentNode->children.end()) {
                    currentNode->children[temPath] = new TrieNode();
                }
                currentNode = currentNode->children[temPath];

                if (currentNode->isEnd) {
                    isSubfolder = true;
                    break;
                }

                temPath = "";
            }
        }

        if (isSubfolder) return false; 
        
        currentNode->isEnd = true;
        if (!currentNode->children.empty()) return false;

        return true;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        
        TrieNode* root = new TrieNode();
        vector<string> result;
        
        for (const string& path : folder) {
            if (insertAndCheck(root, path)) {
                result.push_back(path);
            }
        }
        
        return result;
    }
};

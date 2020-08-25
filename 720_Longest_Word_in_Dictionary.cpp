// Trie +DFS
class Solution {
public:
    struct TreeNode {
        char val;
        unordered_map<char, TreeNode*> b2nDict;
        TreeNode(char ifEnd) : val(ifEnd), b2nDict() {}
    };
    
    string longestWord(vector<string>& words) {
        TreeNode * root =  new TreeNode('S');
        
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
        }   
        
        string result = longW(root, "");
        
        return result;
    }
    
    string longW(TreeNode* root, string str) {
        string longStr = str;
        
        for (auto& v : root->b2nDict) {
            if (v.first == 'E') continue;
            
            if (v.second->b2nDict['E']) {
                string tempStr = longW(v.second, str + v.first);
                if (tempStr.size() > longStr.size()) longStr = tempStr;
                else if (tempStr.size() == longStr.size() && tempStr < longStr) longStr = tempStr;
            } 
        }
        
        return longStr;
    }
};

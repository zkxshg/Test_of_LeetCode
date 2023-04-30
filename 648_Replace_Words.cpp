// https://leetcode.com/problems/replace-words/
// hash table

class Solution {
public:
    vector<string> split(string s) {
        vector<string> res;
        string tem = "";
        
        for (char c : s) {
            if (c == ' ') {
                res.push_back(tem); tem = "";
            }
            else tem += c;
        }
        res.push_back(tem);
        return res;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string, int> roots;
        for (string& s : dictionary) roots[s]++;
        
        vector<string> words = split(sentence);
        
        string res = ""; 
        for (string& w : words) {
            string tem = ""; bool suc = false;
            for (char c : w) {
                tem += c;
                
                if (roots[tem]) {
                    res += tem; res += " "; suc = true;
                    break;
                }
            }
            
            if (!suc) {
                res += tem; res += " ";
            }
        }
        
        res.pop_back();
        return res;
    }
};

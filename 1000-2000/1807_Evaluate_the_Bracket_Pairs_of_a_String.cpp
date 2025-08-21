// https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/
// hash table

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        
        unordered_map<string, string> ans;
        for (auto& v : knowledge) ans[v[0]] = v[1];
        
        string res; int pos = 0;
        while (pos < n) {
            if (s[pos] == '(') {
                int nex = pos + 1; while (s[nex] != ')') nex++;
                
                string key = s.substr(pos + 1, nex - pos - 1);
                
                if (ans[key].size()) res += ans[key];
                else res += "?";
                
                pos = nex;
            }
            else res += s[pos];
            
            pos++;
        }
        
        return res;
    } 
};

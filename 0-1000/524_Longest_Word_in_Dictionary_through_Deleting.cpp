// Two pointers: O(mn)
// By suffix trie can be reduced to O(mlogn)
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int n = s.size(), m = d.size();
        
        string res = "";
        for (string str : d) {
            bool sat = true;
            
            int pos = 0;
            for (char ch : str) { 
                while (pos < n && s[pos] != ch) pos++;
                
                if (pos < n && s[pos] == ch) pos++;
                else {
                    sat = false;
                    break;
                }
            }
            
            if (sat) {
                if (str.size() > res.size()) res = str;
                else if (str.size() == res.size() && str < res) res = str;
            }
        }
        
        return res; 
    }
};

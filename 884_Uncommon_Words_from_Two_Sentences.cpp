// https://leetcode.com/problems/uncommon-words-from-two-sentences/
// hash table

class Solution {
public:
    vector<string> split(string s) {
        vector<string> res;
        
        string tem = "";
        for (char c : s) {
            if (c == ' ') {
                res.push_back(tem);
                tem = "";
            }
            else tem += c;
        }
        
        res.push_back(tem);
        return res;
    }
    
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> dict1;
        unordered_map<string, int> dict2;
        
        vector<string> words1 =  split(s1);
        vector<string> words2  = split(s2);
        
        vector<string> res;
        
        for (string& w1 : words1) dict1[w1]++;
        for (string& w1 : words2) dict2[w1]++;
        
        for (string& w1 : words1)
            if (!dict2[w1] && dict1[w1] < 2)
                res.push_back(w1);
        
        for (string& w1 : words2)
            if (!dict1[w1] && dict2[w1] < 2)
                res.push_back(w1);
        
        return res;
    }
};

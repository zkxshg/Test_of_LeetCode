// hash map
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> fre;
        for (char c : licensePlate) {
            if (c >= 'a' && c <= 'z') fre[c]++;
            else if (c >= 'A' && c <= 'Z') fre[tolower(c)]++;
        }
        
        string res; int len = 1001;
        
        for (string s : words) {
            unordered_map<char, int> tem;
            for (char c : s) tem[c]++;
            
            bool comp = true;
            for (auto& v : fre) {
                if (tem[v.first] < v.second) {
                    comp = false; break;
                }
            }
               
           if (comp && s.size() < len) {
               len = s.size(); res = s;
           }
        }
        
        return res;
    }
};

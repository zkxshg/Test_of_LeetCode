// update last -> pattern match -> update start
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int len = pattern.size();
        if (len == 1) return true;
        
        if (len == 0 && str.size() == 0) return true;
        else if (len == 0 || str.size() == 0) return false;
        
        unordered_map<char, string> pDict;
        unordered_map<string, bool> strCheck;
        
        int start = 0, last;
        for (int i = 0; i < len; i++) {
            last = str.find(' ', start);
            if (last == str.npos) last = str.size();
            
            string temps = str.substr(start, last - start);
            if (pDict.find(pattern[i]) == pDict.end()){
                if (strCheck.find(temps) == strCheck.end()) {
                    pDict[pattern[i]] = temps;
                    strCheck[temps] = true;
                }
                else return false;
            } 
            else if (pDict[pattern[i]] != temps) return false; 

            start = last + 1;
            if (i < len -1 && start > str.size()) return false;
        }
        if (last < str.size()) return false;
        
        return true;
    }
    
};

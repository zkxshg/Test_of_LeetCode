// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
// Rabin–Karp

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.size();
        if (s.size() < n) return s;
        
        map<string, bool> dict;
        dict[part] = true;
        
        bool get = true;
        while (get && s.size() >= n) {
            get = false;
            
            int m = s.size();
            for (int i = 0; i <= m - n; i++) {
                if (dict.find(s.substr(i, n)) != dict.end()) {
                    get = true;
                    s.erase(i, n);
                    break;
                }
            }
        }
        
        return s;
    }
};

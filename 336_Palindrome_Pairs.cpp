/ https://leetcode.com/problems/palindrome-pairs/
// Rabin–Karp
class Solution {
public:
    
    bool ifPali(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size(); if (n < 2) return {};
        
        // Map to rec if word is pali
        unordered_map<int, int> wp;
        for (int i = 0; i < n; i++) {
            if (ifPali(words[i])) wp[i] = 1;
            else wp[i] = -1;
        }
            
        // Map from word to reverse
        unordered_map<string, int> dict; int counter = 1; string rs;
        for (int i = 0; i < n; i++) {
            string str = words[i];
            rs.assign(str.rbegin(), str.rend());
            dict[rs] = i; 
        }
        
        vector<vector<int>> result; 
        for (int i = 0; i < n; i++) {
            string s1 = words[i]; int l1 = s1.size(), ifi = wp[i];
            
            if (s1.empty()) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    if (wp[j] > 0) {
                        result.push_back({i, j}); result.push_back({j, i});
                    }
                }
                continue;
            }
            
            string ls = "", rs = "";
            
            for (int j = 0; j < l1; j++) {
                ls += s1[j]; rs = s1.substr(j + 1);
                
                if (dict.find(ls) != dict.end() && dict[ls] != i && ifPali(rs))
                    result.push_back({i, dict[ls]});
                
                if (!rs.empty() && dict.find(rs) != dict.end() && dict[rs] != i && ifPali(ls))
                    result.push_back({dict[rs], i});
            }         
        }
      
        return result;
    }
};

// word to word
class Solution {
public:
    
    bool ifPali(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size(); if (n < 2) return {};
        
        // Map to rec if word is pali
        unordered_map<int, int> wp;
        for (int i = 0; i < n; i++) {
            if (ifPali(words[i])) wp[i] = 1;
            else wp[i] = -1;
        }
            
        // Map from word to counter
        unordered_map<string, int> dict; int counter = 1; string rs;
        for (int i = 0; i < n; i++) {
            string str = words[i];
            
            if (!dict[str]) {
                dict[str] = counter;
                if (wp[i] < 0) {
                    rs.assign(str.rbegin(), str.rend()); dict[rs] = -counter;
                }
                counter++;
            }    
        }
        
        vector<vector<int>> result; 
        for (int i = 0; i < n - 1; i++) {
            int ifi = wp[i];
            
            for (int j = i + 1; j < n; j++) {
                int ifj = wp[j];
                
                string s1 = words[i], s2 = words[j]; 
                int l1 = s1.size(), l2 = s2.size();
                
                if (s1.empty() || s2.empty()) { // s1 or s2 = ""
                    if (ifi > 0 && ifj > 0) {
                        result.push_back({i, j}); result.push_back({j, i});
                    }
                    continue;
                }
                
                if (l1 < l2) {
                    string rs1 = s2.substr(l2 - l1, l1);
                    if(dict[s1] == dict[rs1] * ifi)
                        if (ifPali(s2.substr(0, l2 - l1)))
                            result.push_back({i, j});
                    
                    
                    string rs2 = s2.substr(0, l1);
                    if(dict[s1] == dict[rs2] * ifi)
                        if (ifPali(s2.substr(l1, l2 - l1)))
                            result.push_back({j, i});                    
                }
                else {
                    string rs1 = s1.substr(l1 - l2, l2);
                    if(dict[s2] == dict[rs1] * ifj)
                        if (ifPali(s1.substr(0, l1 - l2)))
                            result.push_back({j, i});
                    
                    string rs2 = s1.substr(0, l2);
                    if(dict[s2] == dict[rs2] * ifj)
                        if (ifPali(s1.substr(l2, l1 - l2)))
                            result.push_back({i, j});
                } 
            }
        }
        
        return result;
        
    }
};

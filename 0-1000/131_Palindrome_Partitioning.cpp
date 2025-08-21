// https://leetcode.com/problems/palindrome-partitioning/
// DP
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.size(); if (len < 2) return {{s}};
        
        vector<vector<string>> result;
        vector<string> temp;
        addPali(result, s, temp);
        return result;
    }
    
    void addPali(vector<vector<string>>& result, string s, vector<string> temp) {
        if (s.empty()) result.push_back(temp);
        else {
            int len = s.size();
            for (int i = 0; i < len; i++) {
                if (s[i] == s[0]) {
                    string sub = s.substr(0, i + 1);
                    if (ifPali(sub)) {
                        temp.push_back(sub);
                        addPali(result, s.substr(i + 1, len - i - 1), temp);
                        temp.pop_back();
                    }
                }
            }
        }   
    }
    
    bool ifPali(string& s) {
        int l = 0, r = s.size()- 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
};

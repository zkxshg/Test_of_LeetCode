// https://leetcode.com/problems/minimum-window-substring/
// sliding window

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        
        vector<int> low(26);
        vector<int> up(26);
        
        // char-fre of t
        for (char c : t) {
            if (c >= 'A' && c <= 'Z') up[c - 'A']++;
            if (c >= 'a' && c <= 'z') low[c - 'a']++;
        }
        // for (int i : up) cout << i << ", "; cout << endl;
        // for (int i : low) cout << i << ", "; cout << endl;
        
        int len = m + 1, res_st = 0, res_en = m - 1;
        
        vector<int> lowS(26);
        vector<int> upS(26);
        
        int st = 0, en = 0;
        while (en < m) {
            // en forward
            while (en < m) {
                // add
                char c = s[en]; en++;
                if (c >= 'A' && c <= 'Z') upS[c - 'A']++;
                if (c >= 'a' && c <= 'z') lowS[c - 'a']++;
                
                // check 
                bool sub = true;
                for (int i = 0; i < 26; i++) {
                    if (up[i] > upS[i] || low[i] > lowS[i]) {
                        sub = false; break;
                    }
                }
                
                if (sub) {
                    if (len > m) {
                        res_st = st; res_en = en; len = res_en - res_st;
                    }
                    else if (en - st < len) {
                        res_st = st; res_en = en; len = res_en - res_st;
                    }
                    break;
                }
            }
            
            // for (int i : upS) cout << i << ", "; cout << endl;
            // for (int i : lowS) cout << i << ", "; cout << endl;
            // cout << st << ":" << en << endl;
            
            // st forward
            bool meet = true;
            while (meet) {
                // delete
                char c = s[st]; st++; // cout << c << ": ";
                if (c >= 'A' && c <= 'Z') upS[c - 'A']--;
                if (c >= 'a' && c <= 'z') lowS[c - 'a']--;
                
                // check 
                bool sub = true;
                for (int i = 0; i < 26; i++) {
                    if (up[i] > upS[i] || low[i] > lowS[i]) {
                        sub = false; break;
                    }
                }
                
                if (sub) {
                    if (en - st < len) {
                        res_st = st; res_en = en; len = res_en - res_st;
                    }
                }
                else meet = false;
            }   
            // cout << st << ":" << en << endl;
            
        } 
        
        if (len > m) return "";
        
        string res; res.assign(s.begin() + res_st, s.begin() + res_en);
        
        return res;
    }
};

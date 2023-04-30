// https://leetcode.com/problems/pyramid-transition-matrix/
// DP + BFS

class Solution {
public:
    unordered_map<string, int> WA;
    
    bool pyRow(string& down, unordered_map<char, unordered_map<char, string>>& tops) {
        int n = down.size();
        if (n == 1) return true;
            
        vector<string> cand;
        
        char ch1 = down[0], ch2 = down[1];
        if (tops[ch1][ch2].empty()) return false;
        else {
            string tm = "";
            for (char ch3 : tops[ch1][ch2]) cand.push_back(tm + ch3);
        }
        
        
        for (int j = 1; j < n - 1; j++) {
            vector<string> tem; 

            char c1 = down[j];
            char c2 = down[j + 1];
            
            if (tops[c1][c2].empty()) return false;

            for (char c3 : tops[c1][c2]) {
                
                for (string& s : cand) {
                    if (tops[s.back()][c3].empty()) continue;
                    // string ns = s; ns += c3; tem.push_back(ns);
                    tem.push_back(s + c3);
                    // cout << ns << endl;
                }
            } 
            if (cand.empty()) return false;
            cand = tem;
        }
        // for (string& s : cand) cout << s << ","; cout << endl;
        for (string& s : cand) 
            if (pyRow(s, tops)) return true;
        
        return false;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<char, unordered_map<char, string>> tops;
        WA.clear();
        
        for (auto& all : allowed) tops[all[0]][all[1]] += all[2];

        return pyRow(bottom, tops);
    }
};

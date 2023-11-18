// https://leetcode.com/problems/longest-string-chain/
// hash table

class Solution {
public:
    static bool cmp(string& a, string& b) {
        return a.size() < b.size();
    }
    
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dict;
        
        unordered_map<string, set<string>> pred;
        
        sort(words.begin(), words.end(), cmp);
        // for (auto& s : words) cout << s << ","; cout << endl;
        
        for (auto& s : words) {
            dict[s]++;
            
            int len = s.size();
            if (len < 2) continue;
            
            for (int i = 0; i < len; i++) {
                string pre = s.substr(0, i) + s.substr(i + 1);
                if (dict[pre]) pred[pre].insert(s);
            } 
        }
        
        int res = 1;
        set<string> bfs(words.begin(), words.end());
        while (!bfs.empty()) {
            set<string> nex;
            
            for (auto& s : bfs) {
                if (pred[s].empty()) continue;   
                for (auto& ns : pred[s]) nex.insert(ns);
            }
            
            bfs = nex;
            if (!bfs.empty()) res++;
        }
        
        return res;
    }
};

// https://leetcode.com/problems/cracking-the-safe/
// DFS

class Solution {
public:
    unordered_map<string,int> dict;
    int n0, k0;
    string res;
    
    bool dfs(string s){
        if(dict[s]) return false;
        
        bool st = false; dict[s]++; string t;
        
        if(s.size() == n0) t = s.substr(1);
        else t = s;
        
        for(int i = 0; i < k0; i++){
            char ch = '0' + i;
            st = st | dfs(t + ch);
        }
        
        if(s.size() == n0 || st) res = res + s.back();
        
        return (s.size() == n0 || st);
    }
    
    string crackSafe(int n, int k) {
        res = ""; dict.clear(); n0 = n; k0 = k; 
        dfs("0");
        return res;
    }
};

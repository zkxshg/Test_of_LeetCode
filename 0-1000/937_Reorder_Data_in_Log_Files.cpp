// https://leetcode.com/problems/reorder-data-in-log-files/
// hash table + sorting

class Solution {
public:
    pair<string, string> split(string s) {
        int p = 0;
        while (s[p] != ' ') p++;
        
        pair<string, string> res;
        res.first = s.substr(0, p);
        res.second = s.substr(p + 1);
        return res;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        unordered_map<string, vector<string>> ids;
        
        int n = logs.size();
        
        vector<string> ll;
        vector<string> dl;
        
        for (string& s : logs) {
            pair<string, string> log = split(s);
            
            if (log.second[0] >= '0' && log.second[0] <= '9') dl.push_back(s);
            else {
                ids[log.second].push_back(log.first);
                ll.push_back(log.second);
            }    
        }
        
        for(auto& p : ids)
            if (p.second.size() > 1)
                sort(p.second.begin(), p.second.end(), greater<string>());
        
        sort(ll.begin(), ll.end());
        
        vector<string> res;
        for (string& s : ll) {
            string tm = ids[s].back() + " "; ids[s].pop_back();
            tm += s; 
            res.push_back(tm); 
        }
        for (string& s : dl) res.push_back(s);
        
        return res;
    }
};

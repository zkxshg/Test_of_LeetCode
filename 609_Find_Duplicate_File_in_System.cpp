// https://leetcode.com/problems/find-duplicate-file-in-system/
// hash table

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int n = paths.size();
        
        unordered_map<string, vector<string> > dict;
        
        for (int i = 0; i < n; i++) {
            string& s = paths[i];
            
            int bk = s.find(" ");
            if (bk == string::npos) continue;
            string dir = s.substr(0, bk);
            
            while (bk != string::npos) {
                int nex = s.find(" ", bk + 1);
                
                int cl = s.find("(", bk), cr = s.find(")", bk);
                
                string file =  s.substr(bk + 1, cl - bk - 1);
                string content = s.substr(cl, cr - cl + 1);
                //cout << file << ":" << content << endl;
                
                dict[content].push_back(dir + "/" + file);
                
                bk = nex;
            }
            // cout << dir << endl;
        }
        
        vector<vector<string>> res;
        for (auto& p : dict) 
            if (p.second.size() > 1)
                res.push_back(p.second);
        
        return {res};
    }
};

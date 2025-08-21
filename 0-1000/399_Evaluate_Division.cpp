// https://leetcode.com/problems/evaluate-division/
// graph + union-find
class Solution {
public:
    unordered_map<string, string> strp;
    unordered_map<string, int> maps;
    vector<vector<double> > dist;
    
    // find
    string find(string p) {
        while (strp[p] != p) p = strp[p];
        return p;
    }
    
    // union
    void Qunion(string p, string q) {
        string rootP = find(p);
        string rootQ = find(q);
        
        if (rootP != rootQ) {  
            // graph
            if (dist[maps[rootP]][maps[rootQ]] == 0.0) {
                double div = dist[maps[q]][maps[p]];
                
                while (strp[p] != p) {
                    div *=  dist[maps[p]][maps[strp[p]]];
                    p = strp[p];
                }
                while (strp[q] != q) {
                    div *=  dist[maps[strp[q]]][maps[q]];
                    q = strp[q];
                }
                dist[maps[rootQ]][maps[rootP]] = div;
                dist[maps[rootP]][maps[rootQ]] = 1 / div;
            }
            // union
            strp[rootP] = rootQ; 
        }  
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        strp.clear(); maps.clear(); dist.clear();
        
        vector<double> result;
        int len = equations.size(); if (len < 1) return result;
        
        // maps
        int ind = 0;
        for (vector<string> strs : equations) {
            for (string str : strs) {
                if (strp.count(str) == 0) {
                    strp[str] = str;
                    maps[str] = ind;
                    ind++;
                }
            }
        }
        
        // graph + union-find
        dist = vector<vector<double>>(ind, vector<double>(ind, 0.0));
        for (int i = 0; i < len; i++) {
            vector<string> strs = equations[i];
            string p = strs[0];
            string q = strs[1];
            double div = values[i];
            
            dist[maps[p]][maps[q]] = div;
            dist[maps[q]][maps[p]] = 1 / div;
            
            Qunion(p, q);
        }
        
        // graph
        for (vector<string> qurie : queries) {
            string p = qurie[0];
            string q = qurie[1];
            
            if (strp.count(p) == 0 || strp.count(q) == 0) {
                result.push_back(-1.0);
                continue;
            }
            
            string rootP = find(p);
            string rootQ = find(q);
            
            if (rootP != rootQ) {
                result.push_back(-1.0);
                continue;
            }
            
            double res = 1.0;
            while (strp[p] != p) {
                res *=  dist[maps[p]][maps[strp[p]]];
                p = strp[p];
            }
            while (strp[q] != q) {
                res *=  dist[maps[strp[q]]][maps[q]];
                q = strp[q];
            }
            
            result.push_back(res);
        }
        
        return result;
        
    }
};

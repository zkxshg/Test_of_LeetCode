// search
bool compare(string &a,string &b){
    return a.length()>b.length();
}
class Solution {
public:
    
    int minimumLengthEncoding(vector<string>& words) {
        
        sort(words.begin(),words.end(),compare);
        string res="";
        res=res+words[0]+"#";
        
        for(int i=1;i<words.size();i++){
            
            int pos=res.find(words[i]+"#");
            if(pos!=-1)
                continue;
            else
                res+=words[i]+"#";
            
        }
        
        return res.length();
        
    }
};

// stack
class Solution {
public:
    
    static bool cmp(string& a, string& b) {
        return a.size() > b.size();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        int len = words.size(); if (len < 2) return words[0].size() + 1;
        int res = 0;
        
        sort(words.begin(), words.end(), cmp);
        
        while (!words.empty()) {
            string tes = words.back();
            words.pop_back();
            
            bool get = false;
            for (string str : words) {
                if (ifPars(str, tes)) {
                    get = true;
                    break;
                }
            }
            
            if (!get) res += tes.size() + 1;   
        }
        
        return res;
    }
    
    bool ifPars(string& a, string& b) {
        int al = a.size(), bl = b.size();
        int len = min(al, bl);
        
        for (int i = 1; i <= len; i++) 
            if (a[al - i] != b[bl - i]) return false;
        
        return true;
    }
};

// union find
class Solution {
public:
    
    static bool cmp(string& a, string& b) {
        return a.size() > b.size();
    }
        
    unordered_map<int, int> par;
    
    int minimumLengthEncoding(vector<string>& words) {
        int len = words.size(); if (len < 2) return words[0].size() + 1;
        int n = len;
        
        sort(words.begin(), words.end(), cmp);
        
        par.clear();
        
        vector<vector<int> > lcs(n, vector<int>(n, -1));
        
        for (int i = 0; i < len; i++) par[i] = i;
        
        for (int i = 0; i < len - 1; i++) {
            int ii = i;
            
            for (int j = i + 1; j < len; j++) {
                if (par[i] != i || par[j] != j) break;
                
                int ij = id(j);
                
                if (ii != ij) {
                    if (lcs[ii][ij] < 0) {
                        if (ifPar(words, ii, ij)) lcs[ii][ij] = 1;
                        else lcs[ii][ij] = 0;
                        
                        lcs[ij][ii] = lcs[ii][ij];
                    }
                    if (lcs[ii][ij]) {
                        if (words[ii].size() < words[ij].size()) par[ii] = par[ij];
                        else par[ij] = par[ii];
                    }
                } 
            }
        }
        
        int res = 0;
        for (int i = 0; i < len; i++) 
            if (par[i] == i) res += words[i].size() + 1;
        
        return res;
    }
    
    int id(int p) {
        while (par[p] != p) p = par[p];
        return p;
    }
    
    bool ifPar(vector<string>& words, int a, int b) {
        string as, bs;
        
        if (words[a].size() < words[b].size()) {
            as = words[a]; bs = words[b];
        }
        else {
            bs = words[a]; as = words[b];
        }
        
        int al = as.size(), bl = bs.size();
        for (int i = 1; i <= al; i++) 
            if (as[al - i] != bs[bl - i]) return false;
        
        return true;
    }
};

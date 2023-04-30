// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
// BFS + bitset

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        
        vector<int> fres;
        
        vector<string> newA;
            
        for (int i = 0; i < n; i++) {
            bool uni = true;
            
            bitset<32> fre(0);
            
            for (char c : arr[i]) {
                if (fre[c - 'a']) {
                    uni = false;
                    break;
                }
                
                fre[c - 'a'] = 1;
            }
            
            if (!uni) continue;
            
            newA.push_back(arr[i]);
            fres.push_back(fre.to_ulong());
        }
        
        arr = newA; n = arr.size();
        
        vector<vector<int> > bfs;
        vector<int> bFre;
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            bfs.push_back({i});
            bFre.push_back(fres[i]);
            
            res = max(res, int(arr[i].size()));
        }
        
        while (!bfs.empty()) {
            vector<vector<int> > tmp;
            vector<int> tmpL;
            
            int b = bfs.size();
            
            for (int i = 0; i < b; i++) {
                int tail = bfs[i].back();
                
                if (tail < n - 1) {
                    
                    for (int j = tail + 1; j < n; j++) {
                        
                        bitset<32> fre(bFre[i]);
                        
                        bool uni = true;
                        for (char c : arr[j]) {
                            if (fre[c - 'a']) {
                                uni = false; break;
                            }
                            else fre[c - 'a'] = 1;
                        }
                        
                        if (!uni) continue;
                        
                        vector<int> v = bfs[i]; v.push_back(j);
                        
                        tmp.push_back(v); tmpL.push_back(fre.to_ulong());
                        
                        res = max(res, int(fre.count()));
                    }    
                }
                
            }
            
            bfs = tmp; bFre = tmpL;
        }
        
        return res;      
    }
};

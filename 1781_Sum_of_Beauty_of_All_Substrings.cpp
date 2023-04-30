// hash table
class Solution {
public:
    int beautySum(string s) {
        int len = s.size(); if (len < 3) return 0;
        
        //if (s == "xzvfsppsjfbxdwkqe") return 64;
        //if (s == "rnhsvsfbdlizrzteqryfdrntvdorniitmldthzlsodsidycmsiszowwggppwfmqsrqfukrhxlivjp") return 7585;
        
        int res = 0;
        
        for (int i = 0; i < len - 2; i++) {
            unordered_map<int, int> dict;
            dict[s[i]]++; dict[s[i + 1]]++;
            
            bool bea = false;
            
            for (int j = i + 3; j <= len; j++) {
                dict[s[j - 1]]++;
                
                if (!bea) {
                    int fre = 0;
                    for (auto& v : dict) fre++;
                    if (fre > 1) bea = true;
                }
                
                if (bea) {
                    int minFre = 501, maxFre = 0;
                    for (auto& v : dict) {
                        minFre = min(minFre, v.second);
                        maxFre = max(maxFre, v.second);
                    }
                    res += maxFre - minFre;
                    
                    //cout << "maxFre = " << maxFre << ", minFre = " << minFre << ""
                }
                
                //cout << "i = " << i << ", j = " << j << ", bea = " << calBeauty(s.substr(i, j - i)) << endl;
                //for (int k = i; k < j; k++) cout << s[k]; cout << endl;
            }
        }
        
        return res;
    }
    
    bool ifBeauty(string s) {
        unordered_map<int, int> dict;
        int fre = 0;
        
        for (char ch : s) {
            if (!dict[ch]) fre++;
            dict[ch]++;
        }
        
        if (fre > 1) return true;
        return false;
    }
    
    int calBeauty(string s) {
        unordered_map<int, int> dict;
        int minFre = 501, maxFre = 0;
        
        for (char ch : s) dict[ch]++;
        for (auto& v : dict) {
            minFre = min(minFre, v.second);
            maxFre = max(maxFre, v.second);
        }
        
        return maxFre - minFre;
    }
};

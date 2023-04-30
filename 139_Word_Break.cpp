// https://leetcode.com/problems/word-break/
// Rabin-Karp algo
class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int slen = s.size(), wlen = wordDict.size();
        if (slen == 0) return true;
        if (wlen == 0) return false;
        
        if(find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) return true;
        
        map<string, bool> dict;
        for (string str : wordDict) dict[str] = true;
        
        deque<bool> dij(slen + 1, false); dij[0] = true;
        for (int i = 1; i <= slen; i++) {
            for (int j = 0; j < i; j++) {
                if (dij[j]) {
                    if(dict[s.substr(j, i - j)]) {
                        dij[i] = true; break;
                    };
                }
            }
        }
        
        return dij[slen];
    }
};

// binary search + DP + trick
class Solution {
public:
    unordered_set<string>st;
    
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0) return true;
        if (wordDict.size() == 0) return false;
        
        if(st.find(s) != st.end()) return false;
        
        if(find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) return true;
        
        int lenWD = wordDict.size();
        sort(wordDict.begin(), wordDict.end());
        
        int temp = biSearch(s, wordDict, 0, lenWD - 1);
        
        if (s.substr(0, wordDict[temp].size()) == wordDict[temp]) {
            if (s.size() == wordDict[temp].size()) return true;
            if (wordBreak(s.substr(wordDict[temp].size()), wordDict)) return true;
        }
        
        for (int i = 1; i <= s.size(); i++) {
            if (find(wordDict.begin(), wordDict.end(), s.substr(0, i)) != wordDict.end()) {
                if (wordBreak(s.substr(i), wordDict)) return true;
            }                
        }
        
        st.insert(s);
        return false;
    }
    
    int biSearch(string s, vector<string>& wordDict, int start, int least) {
        if (start == least) return start;
        else {
            unsigned int k = (least + start) / 2;
            string midStr = s.substr(0, wordDict[k].size());
            
            if (midStr == wordDict[k]) return k;
            else if (midStr < wordDict[k]) return biSearch(s, wordDict, start, k);
            else return biSearch(s, wordDict, k + 1, least);
        }
        return -1;
    }
};

// DP
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0) return true;
        if (wordDict.size() == 0) return false;
        
        if(find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) 
            return true;
        
        for (int i = 1; i <= s.size(); i++) {
            if (find(wordDict.begin(), wordDict.end(), s.substr(0, i)) != wordDict.end()) {
                if (wordBreak(s.substr(i), wordDict)) return true;
            }                
        }
        
        return false;
    }

};

// binary search + DP
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0) return true;
        if (wordDict.size() == 0) return false;
        
        if(find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) 
            return true;
        
        int lenWD = wordDict.size();
        sort(wordDict.begin(), wordDict.end());
        
        int temp = biSearch(s, wordDict, 0, lenWD - 1);
        
        if (s.substr(0, wordDict[temp].size()) == wordDict[temp]) {
            if (s.size() == wordDict[temp].size()) return true;
            
            if (wordBreak(s.substr(wordDict[temp].size()), wordDict)) return true;
            
            for (int i = 1; i <= s.size(); i++) {
                if (find(wordDict.begin(), wordDict.end(), s.substr(0, i)) != wordDict.end() && wordBreak(s.substr(i), wordDict)) return true;
            }
        }
        
        return false;
    }
    
    int biSearch(string s, vector<string>& wordDict, int start, int least) {
        if (start == least) return start;
        else {
            unsigned int k = (least + start) / 2;
            string midStr = s.substr(0, wordDict[k].size());
            
            if (midStr == wordDict[k]) return k;
            else if (midStr < wordDict[k]) return biSearch(s, wordDict, start, k);
            else return biSearch(s, wordDict, k + 1, least);
        }
        return -1;
    }
};

// https://leetcode.com/problems/vowels-of-all-substrings/
// DP

class Solution {
public:
    #define ll long long
    
    long long countVowels(string word) {
        ll res = 0;
        
        unordered_map<char, int> vow;
        vow['a'] = 1; vow['e'] = 2; vow['i'] = 3; vow['o'] = 4; vow['u'] = 5;
        
        int len = word.size();
        
        vector<ll> ssNum(len); // substring number  
        ssNum[0] = 1;
        
        ll temV = 0; // vow number
        
        if (vow[word[0]]) {
             temV = 1; res = 1;
        }
        
        for (int i = 1; i < len; i++) {
            ssNum[i] = ssNum[i - 1] + 1;
            
            if (vow[word[i]]) temV += ssNum[i - 1] + 1;
            
            res += temV;
        }
        
        return res;
    }
};

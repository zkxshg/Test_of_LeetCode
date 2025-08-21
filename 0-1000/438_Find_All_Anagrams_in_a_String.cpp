class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lens = s.size();
        int lenp = p.size();
        
        vector<int> result;
        if (lens < lenp) return result;
        if (s == p) {
            result.push_back(0);
            return result;
        }
        
        bool first = false;
        char a = '0';
        for (int i = 0; i < lenp; i++) a ^= p[i];
        for (int i = 0; i < lenp; i++) a ^= s[i];
        if (isAnagram(s.substr(0,lenp), p)) {
            first = true;
            result.push_back(0);
        }
        if (lens == lenp) return result;
        
        for (int i = 1; i < lens - lenp + 1; i++){
            a ^= s[i-1];
            a ^= s[i+lenp-1];
            if (!first && s[i-1] == s[i+lenp-1]) continue; // faster 1
            if (a == '0' && first) result.push_back(i); // faster 2
            else if (isAnagram(s.substr(i,lenp), p)){
                result.push_back(i);
                first = true;
            }
            else if(first) first = false;
        }
        return result;
    }
    
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t) return true;
        else return false;
    }
};

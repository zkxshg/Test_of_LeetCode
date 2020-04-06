// same to 438_Find_All_Anagrams_in_a_String.cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int lenp = s1.size();
        int lens = s2.size();
        
        bool result = false;
        if (lens < lenp) return result;
        if (s1 == s2) return true;
        
        char a = '0';
        for (int i = 0; i < lenp; i++) a ^= s1[i];
        for (int i = 0; i < lenp; i++) a ^= s2[i];
        if (a == '0' && isAnagram(s2.substr(0,lenp), s1)) return true;
        
        for (int i = 1; i < lens - lenp + 1; i++){
            if (s2[i-1] == s2[i+lenp-1]) continue;
            a ^= s2[i-1];
            a ^= s2[i+lenp-1];
            if (a == '0' && isAnagram(s2.substr(i,lenp), s1)) return true; 
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

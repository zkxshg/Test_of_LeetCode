// hash map
class Solution {
public:
    bool halvesAreAlike(string s) {
        int len = s.size(); 
        
        unordered_map<char, int> s1Dict;
        unordered_map<char, int> s2Dict;
        
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (char ch : vowels) s1Dict[ch] = 0;
        for (char ch : vowels) s2Dict[ch] = 0;
        
        for (int i = 0; i < len/2; i++) s1Dict[s[i]]++;
        for (int i = len/2; i < len; i++) s2Dict[s[i]]++;
        
        int s1Num = 0;
        for (char ch : vowels) s1Num += s1Dict[ch];
        
        int s2Num = 0;
        for (char ch : vowels) s2Num += s2Dict[ch];
        
        return (s1Num == s2Num);
    }
};

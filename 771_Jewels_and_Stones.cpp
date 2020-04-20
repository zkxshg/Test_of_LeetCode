// unordered_map<char, int> jDict
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int lenj = J.size();
        int lens = S.size();
        if (lenj == 0 ||lens == 0) return 0;
        
        unordered_map<char, int> jDict;
        for (char i = 'a'; i <= 'z'; i++) jDict[i] = 0;
        for (char i = 'A'; i <= 'Z'; i++) jDict[i] = 0;
        
        for (int i = 0; i < lenj; i++) jDict[J[i]] = 1;
        
        int cou = 0;
        for (int i = 0; i < lens; i++) cou += jDict[S[i]];
        return cou;
    }
};

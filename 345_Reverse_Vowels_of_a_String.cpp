// use pos to save vowels's position
class Solution {
public:
    string reverseVowels(string s) {
        int len = s.size();
        if (len < 2) return s;
        
        vector<int> pos;
        for (int i = 0; i < len; i++){
            if (isVowel(s[i])) pos.push_back(i);
        }
        
        int plen = pos.size();
        if (plen < 2) return s;
        
        char temp;
        for (int i = 0; i < plen / 2; i++) {
            temp = s[pos[i]];
            s[pos[i]] = s[pos[plen-i-1]];
            s[pos[plen-i-1]] = temp;
        }
        return s;
    }
    bool isVowel(char ch){
        if (ch == 'a' || ch == 'A') return true;
        else if (ch == 'e' || ch == 'E') return true;
        else if (ch == 'i' || ch == 'I') return true;
        else if (ch == 'o' || ch == 'O') return true;
        else if (ch == 'u' || ch == 'U') return true;
        return false;
    }
};

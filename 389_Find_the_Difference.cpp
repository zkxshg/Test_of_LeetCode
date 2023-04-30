// XOR
class Solution {
public:
    char findTheDifference(string s, string t) {
        char r = 0;
        for (int i = 0; i < s.size(); i++) r ^= s[i];
        for (int i = 0; i < t.size(); i++) r ^= t[i];
        return r;
    }
};

// string.find()
class Solution {
public:
    char findTheDifference(string s, string t) {
        int lent = t.size();
        if (lent == 0) return t[0];
        
        int pos = -1;
        
        for (int i = 0; i < lent; i++){
            pos = s.find(t[i]);
            if (pos == s.npos) return t[i];
            s.erase(pos,1);
        }
        return t[lent-1];
    }
};

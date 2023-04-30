class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        if (S.size() == 0 && T.size() == 0) return true;
        else if (S.size() == 0 || T.size() == 0) return false;
        
        int pos = 0;
        while (pos < S.size()){
            if (S[pos] == '#'){
                if (pos == 0) S.erase(pos, 1);
                else{
                    S.erase(pos-1, 2);
                    pos--;
                }
            }
            else pos++;
        }
        
        pos = 0;
        while (pos < T.size()){
            if (T[pos] == '#'){
                if (pos == 0) T.erase(pos, 1);
                else{
                    T.erase(pos-1, 2);
                    pos--;
                }
            }
            else pos++;
        }
        
        if (S == T) return true;
        return false;
    }
};

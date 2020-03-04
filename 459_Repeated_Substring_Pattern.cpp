// Check substr with length in [1, len/2]
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        if (len == 0) return true;
        if (len == 1) return false;
        bool result = false;
        for (int i = 1; i <= len / 2 ; i++){
            if (len % i != 0) continue;
            int k = len / i;
            bool match = true;
            for (int j = 1; j < k; j++){
                if (s.substr(0, i) != s.substr(j*i, i)) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result = true;
                break;
            }    
        }
        return result;
    }
};

// recursive
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int len = S.size();
        
        vector<string> res = {""};
        
        for (int i = 0; i < len; i++) {
            char c = S[i];
            int r = res.size();
            
            if (c >= '0' && c <= '9') 
                for (int j = 0; j < r; j++) 
                    res[j] += c;
            else {
                char low, up;
                if (c >= 'a' && c <= 'z') {
                    low = c; up = c - 32;
                }
                else {
                    up = c; low = c + 32;
                }
                
                vector<string> tem(2 * res.size());
                
                for (int k = 0; k < r; k++) {
                    tem[k] = res[k] + low;
                    tem[k + r] = res[k] + up;
                }
                
                res = tem;
            }
        }
        sort(res.begin(), res.end());
        return res;
        
    }
};

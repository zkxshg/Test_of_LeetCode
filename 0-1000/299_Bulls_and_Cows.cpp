// hash table
class Solution {
public:
    string getHint(string secret, string guess) {
        int len = secret.size();
        if (len < 1) return "0A0B";
        
        int A = 0, B = 0;
        unordered_map<int, int> posDict;
        vector<bool> notA(len, true);
        
        for (int i = 0; i < len; i++) {
            if (guess[i] == secret[i]) {       
                A++;
                notA[i] = false;
            }
            else posDict[secret[i] - '0']++;
        }
        
        for (int i = 0; i < len; i++) {
            if (notA[i] && posDict[guess[i] - '0'] > 0) {       
                B++;
                posDict[guess[i] - '0']--;
            }
        }
        
        string result;
        result += to_string(A);
        result += "A";
        result += to_string(B);
        result += "B";
        
        return result;
    }
};

// hash map
class Solution {
public:
    string frequencySort(string s) {
        if (s.size() < 2) return s;
        
        string alphabet = "";
        int maxFre = 0;
        unordered_map<char, int> sDict;
        for (char c : s) {
            sDict[c]++;
            if (sDict[c] > maxFre) maxFre = sDict[c];
            if (sDict[c] == 1) alphabet += c;
        } 
        
        string result = "";
        for (int i = maxFre; i > 0; i--){
            for (int c = 0; c < alphabet.size(); c++) {
                if (sDict[alphabet[c]] == i) {
                    for (int j = 0; j < i; j++) result += alphabet[c];
                    alphabet.erase(c,1);
                    c--;
                }     
            }
            if (alphabet.size() == 0) break;
        }
        return result; 
    }
};

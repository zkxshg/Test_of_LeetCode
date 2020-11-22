// map
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.",
                                "....","..",".---","-.-",".-..","--","-.",
                                "---",".--.","--.-",".-.","...","-","..-",
                                "...-",".--","-..-","-.--","--.."};
        
        unordered_map<string, int> codeBook;
        
        for (string w : words) {
            string code = "";
            for (char ch : w) code += morse[ch - 'a'];
            codeBook[code] = 1;
        }
        
        int res = 0;
        for (auto& v : codeBook) res++;
        
        return res;
    }
};

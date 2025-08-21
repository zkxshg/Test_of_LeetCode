// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// temp.swap(next); vector<string>().swap(next);
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int dsize = digits.size();
        if (dsize == 0) {
            vector<string> result;
            return result;
        }
        
        string str1 = let2str(digits[0]);
        vector<string> temp(str1.size());
        for (int i = 0; i < str1.size(); i++) temp[i] += str1[i];
        if (dsize == 1) return temp;
        
        vector<string> next;
        for (int i = 1; i < dsize; i++){
            str1 = let2str(digits[i]);
            for (int j = 0; j < temp.size(); j++){
                for (int k = 0; k < str1.size(); k++) next.push_back(temp[j] + str1[k]);
            }
            if (i < dsize - 1){
                temp.swap(next);
                vector<string>().swap(next);
            }
        }
        return next;
    }
    string let2str(char letter){
        if(letter == '2') return "abc";
        else if(letter == '3') return "def";
        else if(letter == '4') return "ghi";
        else if(letter == '5') return "jkl";
        else if(letter == '6') return "mno";
        else if(letter == '7') return "pqrs";
        else if(letter == '8') return "tuv";
        else if(letter == '9') return "wxyz";
        return "";
    }
};

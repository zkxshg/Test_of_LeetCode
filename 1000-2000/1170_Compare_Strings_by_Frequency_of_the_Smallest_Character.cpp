// https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
// design
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int lenq = queries.size();
        int lenw = words.size();
        
        vector<int> feqQ(lenq);
        for (int i = 0; i < lenq; i++) feqQ[i] = calFre(queries[i]);
        vector<int> feqW(lenw);
        for (int i = 0; i < lenw; i++) feqW[i] = calFre(words[i]);
        sort(feqW.begin(), feqW.end());
        
        vector<int> result(lenq, 0);
        for (int i = 0; i < lenq; i++){
            for (int j = lenw - 1; j >= 0; j--){
                if (feqW[j] > feqQ[i]) result[i]++;
                else break;
            }
        }
        
        return result;    
    }
    
    int calFre(string str){
        char minch = 'z';
        for (int i = 0; i < str.size(); i++){
            if (str[i] < minch) minch = str[i];
        }
        int cou = 0;
        for (int i = 0; i < str.size(); i++){
            if (str[i] == minch) cou++;
        }
        return cou;
    }
};

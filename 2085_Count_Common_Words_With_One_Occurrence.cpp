// https://leetcode.com/problems/count-common-words-with-one-occurrence/
// hash table

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> dict1;
        unordered_map<string, int> dict2;
        
        for (string& w1 : words1) dict1[w1]++;
        for (string& w1 : words2) dict2[w1]++;
        
        int res = 0;
        
        for (string& w1 : words1)
            if (dict1[w1] == 1 && dict2[w1] == 1) {
                res++; dict1[w1]++;
            }
        
        return res;
    }
};

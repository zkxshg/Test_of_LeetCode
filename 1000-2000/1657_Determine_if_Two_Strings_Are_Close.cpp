// hash map
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        int len = word1.size();
        
        unordered_map<char, int> w1Fre;
        unordered_map<char, int> w2Fre;
        
        unordered_map<int, int> F1Dic;
        unordered_map<int, int> F2Dic;
        
        for (char ch : word1) w1Fre[ch]++;
        for (char ch : word2) w2Fre[ch]++;
        
        for (auto& v : w1Fre) {
            char c = v.first;
            if (w2Fre.count(c) == 0) return false;
        }
        for (auto& v : w2Fre) {
            char c = v.first;
            if (w1Fre.count(c) == 0) return false;
        }
        
        for (auto& v : w1Fre) F1Dic[v.second]++;
        for (auto& v : w2Fre) F2Dic[v.second]++;
        
        for (auto& v : F1Dic) {
            if (F1Dic[v.first] != F2Dic[v.first]) return false;
        }
        
        return true;
    }
};

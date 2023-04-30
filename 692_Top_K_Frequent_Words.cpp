// hash table -> freq -> make_heap
class Solution {
public:
    
    static bool comp(pair<int, string>& s1, pair<int, string>& s2) {
        if (s1.first == s2.first) return s1.second > s2.second;
        return s1.first < s2.first;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        int len = words.size(); if (len < 2) return words;
        
        unordered_map<string, int> freqD;
        for (string word : words) {
            if (freqD.count(word) == 0) freqD[word] = 1;
            else freqD[word]++;
        }
        
        vector<pair<int, string> > wheap;
        for (auto& pa : freqD) {
            wheap.push_back(make_pair(pa.second, pa.first));
        }
        
        make_heap(wheap.begin(), wheap.end(), comp);
        
        vector<string> result;

        while (k > 0) {
            result.push_back(wheap.front().second);
            pop_heap(wheap.begin(), wheap.end(), comp);
            wheap.pop_back();
            k--;
        }
        
        return result;
    }
};

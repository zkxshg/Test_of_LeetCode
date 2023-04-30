// hash table
class Solution {
public:
    int minDeletions(string s) {
        int len = s.size(); if (len == 1) return 0;
        
        unordered_map<char, int> chCount;
        for (char ch : s) chCount[ch]++;
        
        unordered_map<int, int> numCount;
        int maxV = 0;
        for (auto& v : chCount) {
            numCount[v.second]++;
            maxV = max(maxV, v.second);
        }
        
        int res = 0; bool full = false;
        for (int i = maxV; i >= 1; i--) {
            if (numCount[i] > 1) {
                while (numCount[i] > 1) {
                    if (full) {
                        res += i;
                        numCount[i]--;
                        continue;
                    }
                
                    for (int j = i - 1; j >= 0; j--) {
                        if (j == 0) {
                            res += i;
                            full = true;
                            numCount[i]--;
                        }
                        else if (!numCount[j]) {
                            numCount[j] = 1;
                            res += i - j;
                            numCount[i]--;
                            break;
                        }
                    }
                }
            }
        }
        
        return res;
    }
};

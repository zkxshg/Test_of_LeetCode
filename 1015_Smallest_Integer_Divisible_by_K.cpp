// https://leetcode.com/problems/smallest-integer-divisible-by-k/
// math
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K == 1) return 1;
        
        unordered_map<int, int> moduCount; moduCount[1] = 1;
        
        vector<pair<int, int> > moduDict; moduDict.push_back(make_pair(1, 1));

        int modu = 1, lv = 1; 
        while (modu != 0) {
            int teM = (moduDict.back().first * 10) % K;
            
            modu += teM;
            
            modu %= K;
            
            if (modu == 0) return lv + 1;

            if (moduCount[modu] && 
                find(moduDict.begin(), moduDict.end(), make_pair(teM, modu)) != moduDict.end()) 
                return -1;
            
            moduCount[modu]++;
            moduDict.push_back(make_pair(teM, modu));
            
            lv++;
        }
        
        return -1;
    }
};

// https://leetcode.com/problems/can-i-win/
// DP + Bitmask

class Solution {
public:
    int MCI, DT;
    
    vector<int> rec;
    
    bool DP(int aim, int mask){
        if(aim <= 0) return true;

        if(mask == 0) return false;

        if(rec[mask] >= 0) return (rec[mask])? true : false;

        bool win = true;

        for(int i = 0; i < MCI; i++){
            if(mask & (1 << i)) win = (win & !DP(aim - i - 1, mask^(1 << i)));
        }

        rec[mask]= win? 1 : 0;
        
        return win;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int maskLen = (1 << maxChoosableInteger) - 1;
        
        int total = 0; for (int i = 1; i <= maxChoosableInteger; i++) total += i;
        if (total < desiredTotal) return false;
        
        rec.resize(maskLen + 1, -1);
        MCI = maxChoosableInteger; DT = desiredTotal;
        
        for(int i = 0; i < MCI; i++)
            if(DP(DT - (i + 1), maskLen^(1 << i))) return true;
            
        return false;
    }
};

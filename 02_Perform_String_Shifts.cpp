class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int len = shift.size();
        if (len == 0) return s;
        
        int lens = s.size();
        
        int cou0 = 0, cou1 = 0;
        for (int i = 0; i < len; i++){
            if (shift[i][0] == 0) cou0 += shift[i][1];
            else cou1 += shift[i][1];
        }
        
        bool leftMove = true;
        int amou = cou0 - cou1;
        if (cou0 < cou1) {
            leftMove = false;
            amou = -amou;
        }
         
        string result = s;
        amou = amou % lens;
        
        if (leftMove){
            for (int i = 0; i < lens; i++){
                if (i + amou >= lens) result[i] = s[i + amou - lens];
                else result[i] = s[i + amou];
            }
        }
        else {
            for (int i = 0; i < lens; i++){
                if (i - amou < 0) result[i] = s[i - amou + lens];
                else result[i] = s[i - amou];
            }
        }
        return result;
    }
};

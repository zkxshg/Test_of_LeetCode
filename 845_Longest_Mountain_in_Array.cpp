// Two Pointers
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int len = A.size(); if (len < 3) return 0;
        
        bool inc = false, dec = false;
        
        int res = 0, temL = 0;
        for (int i = 0; i < len - 1; i++) {
            if (A[i] == A[i + 1]) {
                if (inc && dec) res = max(res, temL);
                temL = 0;
                dec = inc = false;  
            }
            else if (A[i] > A[i + 1]) {
                if (dec) {
                    temL++;
                    res = max(res, temL);
                }
                else if (inc) {
                    dec = true;
                    temL++;
                    res = max(res, temL);
                } 
            }
            else {
                if (!inc) {
                    inc = true;
                    temL = 2;
                }
                else {
                    if (!dec) temL++;
                    else {
                        res = max(res, temL);
                        temL = 2;
                        dec = false;
                    }
                }
            }
        }
        return res;
    }
};

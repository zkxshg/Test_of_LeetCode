// https://leetcode.com/problems/number-of-digit-one/
// dp + math

// number of 1 in decimal n
class Solution {
public:
    int getLv(int n) {
        int lv = 0;
        while (n) {
            n /= 10; lv++;
        }
        return lv;
    } 
    
    int countDigitOne(int n) {
        if (n <= 1) return n;
        if (n < 10) return 1;
        
        int res = 0; 
        int lv = getLv(n);
        
        vector<int> dec(lv + 1); dec[0] = 0;
        for (int i = 1; i < lv; i++) {
            dec[i] = pow(10, i - 1) + 10 * dec[i - 1];
        }
        
        int head = n / pow(10, lv - 1);
        
        while (n >= 10) {
            // 21435 -> [0, 19999]
            res += head * dec[lv - 1];
            
            // 21435 -> 1435
            n %= int(pow(10, lv - 1));
            
            if (head != 0) {
                if (head == 1) res += n + 1;
                else res += pow(10, lv - 1);
            }
            
            lv--; head = n / pow(10, lv - 1);
        }
        if (n) res++;
        
        return res;
    }
};

// number of 1 in binary n
class Solution {
public:
    int getLv(int n) {
        int lv = 0;
        while (n > (1 << lv)) lv++;
        if (n == (1 << lv)) return lv;
        return lv - 1;
    } 
    
    int countDigitOne(int n) {
        long long res = 0, step = 0;
        while (n) {
            step++;
            
            int lv = getLv(n), comb = 1;
            
            if (lv) comb = lv * (1 << (lv - 1));
            
            res += comb; 
            res += (n - (1 << lv)) * step;
            n -= (1 << lv);
        }
        return res;
    }
};

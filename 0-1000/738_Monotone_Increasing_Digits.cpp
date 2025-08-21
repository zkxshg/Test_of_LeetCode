// https://leetcode.com/problems/monotone-increasing-digits/
// Greedy

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if (n < 10) return n;
        
        vector<int> nele; 
        int on = n;
        while (on) {
            nele.push_back(on % 10);
            on /= 10;
        }
        
        int lv = nele.size();
        reverse(nele.begin(), nele.end());
        //for (int i : nele) cout << i; cout << endl;
        
        // vector<int> sucMin(lv); int tm = nele[lv - 1];
        // for (int i = lv - 1; i >= 0; i--) {
        //     tm = min(nele[i], tm); sucMin[i] = tm;
        // }
        
        int peak = lv;
        for (int i = 0; i < lv - 1; i++) {
            if (nele[i] > nele[i + 1]) {
                peak = i; break;
            }
        }
        while (peak < lv && peak > 0 && nele[peak] == nele[peak - 1]) peak--;
        
        if (peak >= lv) return n;
        
        int res = 0;
        for (int i = 0; i < peak; i++) res = res * 10 + nele[i];
        res = res * 10 + nele[peak] - 1;
        for (int i = peak + 1; i < lv; i++) res = res * 10 + 9;
        
        return res;
    }
};

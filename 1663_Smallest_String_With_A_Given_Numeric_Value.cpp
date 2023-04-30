// greedy
class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";

        for (int i = 0; i < n; i++) res += 'a';
        int strV = n; if (strV == k) return res;
        
        k -= n;
        int pos = n - 1;
        while (k > 0) {
            if (k < 26) {
                res[pos] = 'a' + k;
                return res;
            }
            else {
                res[pos] = 'z';
                k -= 25;
                pos--;
            }
        }
        
        return res;
    }
    
    int numV(char ch) {
        return ch - 'a' + 1;
    }
};

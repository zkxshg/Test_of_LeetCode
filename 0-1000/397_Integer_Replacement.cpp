// https://leetcode.com/problems/integer-replacement/
// Bit Maniputation

class Solution {
public:
    #define ll long long
    
    int integerReplacement(int n) {
        // bitset<32> b(n);
        // cout << b << endl;
        ll tn = n;
        int res = 0;
        while (tn > 1) {
            
            if (tn % 2) {
                if (tn == 3) {
                    res += 2; tn = 1; break;
                }
                
                bitset<32> b(tn);

                if (b[1]) tn += 1;
                else tn -= 1;
            }
            else tn /= 2;
            
            // cout << n << endl;
            res++; 
        }
        
        return res;
    }
};

// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
// math

class Solution {
public:
    int getLucky(string s, int k) {
        vector<int> num;
        for (char c : s) num.push_back(c - 'a' + 1);
        // for (int n : num) cout << n << ","; cout << endl;
        int res = 0;
        for (int i : num) {
            if (i > 9) {
                res += i / 10; res += i % 10;
            }
            else res += i;
        }
        
        for (int i = 1; i < k; i++) {
            int tem = 0;
            
            while (res) {
                tem += res % 10; res /= 10;
            }
            
            res = tem;
        }
        
        return res;
    }
};

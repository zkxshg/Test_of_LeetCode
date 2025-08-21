// Greedy
class Solution {
public:
    string removeKdigits(string num, int k) {
        while (num.size() > 1 && num[0] == '0') num.erase(0,1);
        if (num == "") return "0";
        if (k == 0) return num;
        
        int len = num.size();
        if (len <= k) return "0";
        
        for (int i = 0; i < k + 1; i++) {
            if (num[i] == '0') return removeKdigits(num.substr(i + 1, len - i - 1), k - i);
        }
        
        int minv = -1, pos = -1;
        for (int i = 0; i < len - 1; i++) {
            if ((num[i] - '0') > (num[i + 1] - '0')) {
                num.erase(i, 1);
                return removeKdigits(num, k - 1);
            }
        }
        num.erase(len - 1, 1);
        return removeKdigits(num, k - 1);
    }
};

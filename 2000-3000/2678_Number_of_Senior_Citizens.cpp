// https://leetcode.com/problems/number-of-senior-citizens/?envType=daily-question&envId=2024-08-01
// string

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for (auto& str : details) {
            if ((str[11] - '0') * 10 + (str[12] - '0') > 60) res++;
        }
        return res;
    }
};  

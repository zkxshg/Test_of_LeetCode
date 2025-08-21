// https://leetcode.com/problems/gray-code/
// math

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(pow(2, n)); res[0] = 0; res[1] = 1;   
        for (int i = 2; i <= n; i++) {
            int bonus = pow(2, i - 1);
            for (int j = 0; j < bonus; j++) res[bonus + j] = res[bonus - j - 1] + bonus;
        }
        return res;
    }
};

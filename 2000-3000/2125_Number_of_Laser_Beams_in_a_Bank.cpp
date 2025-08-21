// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
// string

class Solution {
public:
    int countSD(string& str) {
        int num = 0;
        for (char c : str) if (c == '1') num++;
        return num;
    }

    int numberOfBeams(vector<string>& bank) {
        int res = 0, pre = 0;
        for (string& str : bank) {
            int cou = countSD(str);
            if (cou > 0) {
                res += pre * cou;
                pre = cou;
            } 
        }
        return res;
    }
};

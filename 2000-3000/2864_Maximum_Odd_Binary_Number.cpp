// https://leetcode.com/problems/maximum-odd-binary-number/?envType=daily-question&envId=2024-03-01
// sorting

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(), s.end());
        sort(s.begin(), s.end() - 1, greater<char>());
        return s;
    }
};

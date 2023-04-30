// https://leetcode.com/problems/maximum-number-of-balloons/
// hash map

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> dict;
        for (char c : text) dict[c]++;
        int res = 0;
        res = min(dict['b'], dict['a']);
        res = min(dict['n'], res);
        res = min(dict['l'] / 2, res);
        res = min(dict['o'] / 2, res);
        return res;
    }
};

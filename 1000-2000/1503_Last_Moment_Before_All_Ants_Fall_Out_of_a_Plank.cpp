// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/
// Array

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0, lenl = left.size(), lenr = right.size();

        for (int i = 0; i < lenl; i++) res = max(res, left[i]);
        for (int i = 0; i < lenr; i++) res = max(res, n - right[i]);

        return res;       
    }
};

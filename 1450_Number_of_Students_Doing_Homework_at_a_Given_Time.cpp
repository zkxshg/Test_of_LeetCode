// https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/
// array

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int res = 0, n = startTime.size();
        for (int i = 0; i < n; i++) if (startTime[i] <= queryTime && endTime[i] >= queryTime) res++;
        return res;
    }
};

// 3439. Reschedule Meetings for Maximum Free Time I
// Link: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/
// Lang: C++
// Date: 2025-08-21 21:03:33.696 UTC

class Solution {
public:
    #define sT startTime
    #define eT endTime

    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> fT; 
        fT.push_back(sT[0]);
        for (int i = 0; i < n - 1; i++) fT.push_back(sT[i + 1] - eT[i]);
        fT.push_back(eventTime - eT.back());

        // for (int i : fT) cout << i << ","; cout << endl;

        int m = fT.size();
        int res = 0; 
        for (int i = 0; i <= k; i++) res += fT[i];
        int tem = res;

        for (int i = 1; i < m - k; i++) {
            tem -= fT[i - 1]; tem += fT[i + k];
            res = max(tem, res);
        }

        return res;
    }
};

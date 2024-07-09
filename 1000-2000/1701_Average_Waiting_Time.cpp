// https://leetcode.com/problems/average-waiting-time/?envType=daily-question&envId=2024-07-09
// Array

class Solution {
public:
    #define ll long long
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        ll st = 0, ttime = 0;

        for (auto& ctm : customers) {
            int arr = ctm[0], dur = ctm[1];

            if (st <= arr) {
                st = arr + dur;
                ttime += dur;
            }
            else {
                st += dur;
                ttime += (st - arr);
            }
        }

        return (double)ttime / n;
    }
};

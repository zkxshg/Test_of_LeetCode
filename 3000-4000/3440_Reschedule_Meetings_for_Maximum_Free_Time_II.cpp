// 3440. Reschedule Meetings for Maximum Free Time II
// Link: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/
// Lang: C++
// Date: 2025-08-21 21:03:13.190 UTC

class Solution {
public:
    #define pii pair<int, int>
    #define sT startTime
    #define eT endTime

    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> fT, fInd, fEnInd; 
        fT.push_back(sT[0]); fInd.push_back(0); fEnInd.push_back(sT[0]);

        vector<pii> hp;
        hp.push_back({sT[0], 0}); push_heap(hp.begin(), hp.end());

        for (int i = 0; i < n - 1; i++) {
            fT.push_back(sT[i + 1] - eT[i]);
            fInd.push_back(eT[i]); 
            fEnInd.push_back(sT[i + 1]);
            hp.push_back({sT[i + 1] - eT[i], eT[i]}); push_heap(hp.begin(), hp.end());
        }

        fT.push_back(eventTime - eT.back());
        fInd.push_back(eT.back()); 
        fEnInd.push_back(eventTime);
        hp.push_back({eventTime - eT.back(), eT.back()}); push_heap(hp.begin(), hp.end());


        int m = fT.size();
        int res = 0; 
        
        for (int i = 0; i < m - 1; i++) {
            int tem = fT[i] + fT[i + 1];

            int ind1 = fInd[i], ind2 = fInd[i + 1];

            int div = fInd[i + 1] - fEnInd[i];

            // cout << tem << "+" << div << ":" << hp.front().first << endl;

            vector<pii> left;
            while (hp.front().second == ind1 || hp.front().second == ind2) {
                left.push_back(hp.front());
                pop_heap(hp.begin(), hp.end()); hp.pop_back();
            }

            if (div <= hp.front().first) tem += div;

            res = max(res, tem);

            while (!left.empty()) {
                hp.push_back(left.back()); push_heap(hp.begin(), hp.end());
                left.pop_back();
            }

            
        }

        return res;
    }
};

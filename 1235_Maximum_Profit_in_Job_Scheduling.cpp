// https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// sorting + DP

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        
        vector<pair<int, int> > T; map<pair<int, int>, int> P;
        for (int i = 0; i < n; i++) {
            T.push_back(make_pair(endTime[i], startTime[i]));
            P[make_pair(endTime[i], startTime[i])] = profit[i];
        }
        
        sort(T.begin(), T.end());
        
        unordered_map<int, int> DP;
        for (int i = 0; i < n; i++) {
            int temT = T[i].first, temP = P[T[i]];
            
            DP[temT] = max(DP[temT], temP);
            
            bool preTra = false;
            for (int j = i - 1; j >= 0; j--) {
                if (T[j].first == temT) {
                    preTra = true; continue;
                }
                
                if (T[j].first > T[i].second) {
                    if (!preTra) DP[temT] = max(DP[temT], DP[T[j].first]);
                }
                else {
                    DP[temT] = max(DP[temT], DP[T[j].first] + temP); break;
                }
            }
        }
        
        return DP[T.back().first];

    }
};

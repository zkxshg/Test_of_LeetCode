// https://leetcode.com/problems/earliest-possible-day-of-full-bloom/
// Greedy + Sorting

class Solution {
public:
    #define PT plantTime
    #define GT growTime
    
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = PT.size();
        
        vector<pair<int, int> > st;
        for (int i = 0; i < n; i++) st.push_back({PT[i], GT[i]});
        
        sort(st.begin(), st.end(), cmp);
        // for (auto& p : st) cout << p.first << ":" << p.second << ","; cout << endl;
        
        int tt = st.back().first + st.back().second; st.pop_back();
        while (!st.empty()) {
            int pt = st.back().first, gt = st.back().second; st.pop_back();
            
            tt = max(tt, gt); tt += pt; 
        }
        
        return tt;
    }
};

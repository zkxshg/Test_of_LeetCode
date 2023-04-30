// https://leetcode.com/problems/minimum-number-of-refueling-stops/
// Greedy + stack
class Solution {
public:
    #define ll long long
    
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (startFuel >= target) return 0;
        
        ll f = startFuel, pos = 0;
        for (auto& v : stations) {
            if (f < v[0] - pos) return -1;
            f += v[1] - (v[0] - pos); pos = v[0];
        } 
        if (f < target - pos) return -1;
        
        vector<int> st;
        make_heap(st.begin(), st.end());
        
        f = startFuel, pos = 0; int n = stations.size(), res = 0;
        for (int i = 0; i < n; i++) {
            
            vector<int>& sta = stations[i];
            
            int nexCost = 0;
            if (i == n - 1) nexCost = target - pos;
            else nexCost = stations[i + 1][0] - pos;
            
            
            if (f >= nexCost) {
                st.push_back(sta[1]); push_heap(st.begin(), st.end());
            }
            else  {
                st.push_back(sta[1]); push_heap(st.begin(), st.end());
                
                while (f < nexCost) {
                    f += st.front(); res++;
                    pop_heap(st.begin(), st.end()); st.pop_back();
                }
            }
        }
        
        return res;
        
    }
};

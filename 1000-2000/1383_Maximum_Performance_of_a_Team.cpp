// https://leetcode.com/problems/maximum-performance-of-a-team/
// greedy + stack
class Solution {
public:
    #define ll long long 
    static bool cmp(int a, int b) {
        return a > b;
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int, int> > eff_sp;
        for (int i = 0; i < n; i++) eff_sp.push_back(make_pair(efficiency[i], speed[i]));
        
        sort(eff_sp.begin(), eff_sp.end());
        
        vector<ll> maxKsum(n); maxKsum[n - 1] = eff_sp[n - 1].second;
        
        vector<int> st; st.push_back(maxKsum[n - 1]);
        make_heap(st.begin(), st.end(), cmp);
        
        for (int i = 2; i <= n; i++) {
            int spj = eff_sp[n - i].second;
    
            if (i <= k) {
                st.push_back(spj); push_heap(st.begin(), st.end(), cmp);
                
                maxKsum[n - i] = maxKsum[n - i + 1] + spj; 
                // cout << maxKsum[n - i] << "<-" << maxKsum[n - i + 1] << "+" << spj << endl;
            }
            else if (spj > st.front()) {
                maxKsum[n - i] = maxKsum[n - i + 1] - st.front() + spj;
                // cout << maxKsum[n - i] << "<-" << maxKsum[n - i + 1] << "+" << spj << endl;
                
                pop_heap(st.begin(), st.end(), cmp); 
                st.pop_back();
                st.push_back(spj); 
                push_heap(st.begin(), st.end(), cmp);
                // cout <<  st.front() << endl;
            }
            else maxKsum[n - i] = maxKsum[n - i + 1];
        }
        
        
        ll res = 0; ll ub = 1e9 + 7;
        for (int i = 0; i < n; i++) res = max(res, maxKsum[i] * eff_sp[i].first);
        
        return res % ub;
        
    }
};

// https://leetcode.com/problems/total-cost-to-hire-k-workers/description/
// heap + two points

class Solution {
public:
    #define ll long long
    #define pii pair<int, int>

    static bool cmp(pii& a, pii& b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }

    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        int l_en = candidates - 1, r_st = n - candidates;

        vector<pii> hp;

        if (l_en >= r_st) {
            for (int i = 0; i < n; i++) hp.push_back({costs[i], i});
        }
        else {
            for (int i = 0; i <= l_en; i++) hp.push_back({costs[i], i});
            for (int i = r_st; i < n; i++) hp.push_back({costs[i], i});
        }

        make_heap(hp.begin(), hp.end(), cmp); 

        ll cost = 0;
        for (int i = 0; i < k; i++) {
            cost += hp.front().first;

            int pos = hp.front().second;
            pop_heap(hp.begin(), hp.end(), cmp); hp.pop_back();
            
            if (l_en < r_st) {
                if (pos <= l_en) {
                    l_en++; 
                    if (l_en >= r_st) continue; 
                    hp.push_back({costs[l_en], l_en}); push_heap(hp.begin(), hp.end(), cmp);
                }
                else {
                    r_st--;
                    if (l_en >= r_st) continue; 
                    hp.push_back({costs[r_st], r_st}); push_heap(hp.begin(), hp.end(), cmp);
                }
            }
        }

        return cost;   
    }
};

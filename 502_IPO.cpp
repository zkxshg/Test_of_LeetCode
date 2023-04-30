// https://leetcode.com/problems/ipo/
// Greedy + Heap

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        vector<pair<int, int> > cand; int cpos = 0;
        for (int i = 0; i < n; i++) cand.push_back({capital[i], profits[i]});
        sort(cand.begin(), cand.end());
 
        vector<int> hp;
        make_heap(hp.begin(), hp.end());
        
        while (k) {
            while (cpos < n && cand[cpos].first <= w) {
                hp.push_back(cand[cpos].second); push_heap(hp.begin(), hp.end());
                cpos++;
            }
            
            if (hp.empty()) break;
            
            w += hp.front();
             pop_heap(hp.begin(), hp.end()); hp.pop_back();
            
            k--;
        }
        
        return w;
    }
};

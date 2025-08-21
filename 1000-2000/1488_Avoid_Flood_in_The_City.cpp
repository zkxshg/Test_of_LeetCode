// https://leetcode.com/problems/avoid-flood-in-the-city/
// Greedy + Heap

class Solution {
public:
    static bool comp(pair<int, int>& s1, pair<int, int>& s2) {
        if (s1.first == s2.first) return s1.second > s2.second;
        return s1.first >  s2.first;
    }
    
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        
        unordered_map<int, vector<int>> rainDay;
        for (int i = n - 1; i >= 0; i--) 
            if (rains[i] > 0)
                rainDay[rains[i]].push_back(i);
        
        vector<pair<int, int> > hp;
        make_heap(hp.begin(), hp.end(), comp); 
        
        vector<int> res;
        
        unordered_map<int, int> full;
        for (int i = 0; i < n; i++) {
            if (rains[i] > 0) {
                if (full[rains[i]]) return {};
                else {
                    full[rains[i]]++;
                    rainDay[rains[i]].pop_back();
                    
                    if (!rainDay[rains[i]].empty()) {
                        hp.push_back(make_pair(rainDay[rains[i]].back(), rains[i]));
                        push_heap(hp.begin(), hp.end(), comp); 
                        // cout << hp.front().first << ":" << hp.front().second << endl;
                    }
                }
                
                res.push_back(-1);
            }
            else {
                if (hp.empty()) {
                    res.push_back(1); continue;
                }
                
                int lake = hp.front().second;
                full[lake] = 0;
               
                pop_heap(hp.begin(), hp.end(), comp); 
                hp.pop_back(); 
                
                res.push_back(lake);
            }
        }
        
        return res;
    }
};

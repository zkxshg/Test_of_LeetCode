// https://leetcode.com/problems/course-schedule-iii/
// Greedy + heap

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        
        vector<pair<int, int> > ddl;
        for (vector<int>& v : courses) 
            if (v[0] <= v[1]) ddl.push_back(make_pair(v[1], v[0]));
            
        sort(ddl.begin(), ddl.end());
        // for (auto& p : ddl) cout << p.first << ":" << p.second << ","; cout << endl;
        
        int cur = 0;
        
        vector<pair<int, int> > h; 
        make_heap(h.begin(), h.end()); 
           
        for (auto& p : ddl) {
            if (h.empty() || p.first >= cur + p.second) {
                cur += p.second;
                h.push_back({p.second, p.first}); push_heap(h.begin(), h.end()); 
            }
            else if (p.second < h.front().first) {
                cur -= h.front().first;
                pop_heap(h.begin(), h.end()); h.pop_back();
                
                cur += p.second;
                h.push_back({p.second, p.first}); push_heap(h.begin(), h.end()); 
                
            } // for (auto&p : h) cout << p.first << ":" << p.second << ","; cout << " = " << cur; cout << endl;
        }
        
        return h.size();
    }
};

// wrong LatestStartTime
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        vector<pair<int, int> > ddl;
        for (vector<int>& v : courses) 
            if (v[1] >= v[0]) 
                ddl.push_back(make_pair(v[1] - v[0], v[0]));
            
        
        sort(ddl.begin(), ddl.end());
        //for (auto& p : ddl) cout << p.first << ":" << p.second << ","; cout << endl;
        
        int cur = 0;
        
        vector<pair<int, int> > h; 
        make_heap(h.begin(), h.end()); 
           
        for (auto& p : ddl) {
            if (h.empty() || p.first >= cur) {
                cur += p.second;
                h.push_back({p.second, p.first}); push_heap(h.begin(), h.end()); 
            }
            else if (p.second < h.front().first) {
                cur += p.second;
                
                if (cur > h.front().second + h.front().first) {
                    cur -= h.front().first;
                    pop_heap(h.begin(), h.end()); h.pop_back();
                }

                h.push_back({p.second, p.first}); push_heap(h.begin(), h.end()); 
                
            } //for (int i : h) cout << i << ","; cout << " = " << cur; cout << endl;
        }
        
        return h.size();
    }
};

// https://leetcode.com/problems/find-right-interval/
// sorting + binary search

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        unordered_map<int, int> dict;
        for (int i = 0; i < n; i++) dict[intervals[i][0]] = i;
        
        sort(intervals.begin(), intervals.end());
        // for (auto& v : intervals) cout << v[0] << "," << v[1] << endl;
        
        vector<int> res(n, -1);
        for (int i = 0; i < n - 1; i++) {
            bool get = false;
            for (int j = i; j < n; j++) {
                if (intervals[j][0] >= intervals[i][1]) {
                    res[dict[intervals[i][0]]] = dict[intervals[j][0]]; 
                    // cout << dict[intervals[i][0]] << "->" << dict[intervals[j][0]] << endl;
                    get = true; break; 
                }
            }
            // if (get) break;
        }
        
        return res;
        
    }
};

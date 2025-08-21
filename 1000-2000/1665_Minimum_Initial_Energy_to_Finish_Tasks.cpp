// greedy
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if ((a[1] - a[0]) == (b[1] - b[0])) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        }
        return ((a[1] - a[0]) < (b[1] - b[0]));
    }
        
    int minimumEffort(vector<vector<int>>& tasks) {
        int len = tasks.size(); if (len == 1) return tasks[0][1];
        
        int LB = 0;
        for (int i = 0; i < len; i++) LB += tasks[i][0];
        sort(tasks.begin(), tasks.end(), cmp);
        //qsort(tasks.begin(), tasks.end(), cmp);
        
        int res = LB;
        int e = res;
        
        for (int i = len - 1; i >= 0; i--) {
            if (e >= tasks[i][1]) e -= tasks[i][0];
            else {
                int div = tasks[i][1] - e;
                res += div;
                
                e += div;
                e -= tasks[i][0];
            }
        }
        
        return res;
    }
};

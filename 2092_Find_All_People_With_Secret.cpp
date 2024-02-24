// https://leetcode.com/problems/find-all-people-with-secret/
// Union Find

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    unordered_map<int, int> U;
    
    int find(int a) {
        if (!U.count(a)) return U[a] = a;
        if (U[a] == a) return a;
        return U[a] = find(U[a]);
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        U.clear();
        for (int i = 0; i < n; i++) U[i] = i;

        U[firstPerson] = 0;

        sort(meetings.begin(), meetings.end(), cmp);

        int m = meetings.size(), st = 0, en = 0;

        while (st < m) {
            int tm = meetings[st][2];

            en = st;
            while (en < m && meetings[en][2] == tm) en++;

            for (int i = st; i < en; i++) {
                int a = meetings[i][0], b = meetings[i][1];

                int pa = find(a), pb = find(b);

                if (pa == 0) U[pb] = 0;
                else if (pb == 0) U[pa] = 0;
                else U[pb] = pa;
            }

            for (int i = st; i < en; i++) {
                int a = meetings[i][0], b = meetings[i][1];

                int pa = find(a), pb = find(b);

                if (pa != 0) U[a] = a;
                if (pb != 0) U[b] = b; 
            }

            st = en;
        }

        vector<int> res;
        for (int i = 0; i < n; i++) if (find(i) == 0) res.push_back(i);

        return res;
        
    }
};

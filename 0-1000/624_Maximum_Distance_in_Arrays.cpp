// https://leetcode.com/problems/maximum-distance-in-arrays/?envType=daily-question&envId=2024-08-16
// Greedy

class Solution {
public:
    #define pii pair<int, int>

    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();

        pii min_1 = {10001, -1}, min_2 = {10001, -1};
        pii max_1 = {-10001, -1}, max_2 = {-10001, -1};


        for (int i = 0; i < m; i++) {
            vector<int>& v = arrays[i];
            int n = v.size();

            int minD = v[0], maxD = v[n - 1];

            if (minD <= min_1.first) {
                min_2 = min_1;

                if (minD < min_1.first) min_1 = {minD, i};
                else min_1.second = -1; 
            }
            else if (minD <= min_2.first) {
                if (minD < min_2.first) min_2 = {minD, i};
                else min_2.second = -1;
            }

            if (maxD >= max_1.first) {
                max_2 = max_1;

                if (maxD > max_1.first) max_1 = {maxD, i};
                else max_1.second = -1;
            }
            else if (maxD >= max_2.first) {
                if (maxD > max_2.first) max_2 = {maxD, i};
                else max_2.second = -1;
            }
        }

        //cout << max_1.first << ":" << max_1.second << endl;
        //cout << max_2.first << ":" << max_2.second << endl;
        //cout << min_1.first << ":" << min_1.second << endl;
        //cout << min_2.first << ":" << min_2.second << endl;
        if (max_1.second == min_1.second && max_1.second >= 0) {
            int res = -10001;
            if (min_2.first >= -10000) res = max(res, max_1.first - min_2.first);
            if (max_2.first <= 10000) res = max(res, max_2.first - min_1.first);
            return res;
        }

        return max_1.first - min_1.first;
    }
};

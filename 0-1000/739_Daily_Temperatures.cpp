// https://leetcode.com/problems/daily-temperatures/
// DP

class Solution {
public:
    #define T temperatures
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = T.size();
        vector<int> warmer(101);
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            if (warmer[T[i]]) res[i] = warmer[T[i]] - i;
            for (int j = 30; j < T[i]; j++) warmer[j] = i;
        } 
        return res;
    }
};

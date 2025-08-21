// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/
// Greedy + Hash table

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        unordered_map<int, int> fre;
        for (int i : tasks) fre[i]++;

        int res = 0;
        for (auto& p : fre) {
            if (p.second == 1) return -1;
            res += ceil((double)p.second / 3);
        }
        return res;
    }
};

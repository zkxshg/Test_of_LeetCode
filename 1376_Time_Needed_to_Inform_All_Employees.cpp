// https://leetcode.com/problems/time-needed-to-inform-all-employees/
// DFS + hash table

class Solution {
public:
    int needTime(unordered_map<int, unordered_map<int, int>>& path, int id, vector<int>& it) {
        int res = it[id];
        int cost = 0;
        // for (auto& p : path[id]) cout << p.first << ":" << p.second << endl;
        for (auto& p : path[id]) cost = max(cost, needTime(path, p.first, it));
        return res + cost;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, unordered_map<int, int>> path;
        for (int i = 0; i < n; i++) path[manager[i]][i] = informTime[i];
        return needTime(path, headID, informTime);
    }
};

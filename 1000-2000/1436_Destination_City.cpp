// https://leetcode.com/problems/destination-city/
// hash table

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> outdegree;
        for (auto& v : paths) {
            if (!outdegree[v[1]]) outdegree[v[1]] = 0;
            outdegree[v[0]]++;
        }
        for (auto& p : outdegree) {
            if (!p.second) return p.first;
        }
        return "";
    }
};

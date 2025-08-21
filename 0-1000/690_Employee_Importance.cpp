// https://leetcode.com/problems/employee-importance/
// dfs + hash table

class Solution {
public:
    unordered_map<int, int> imp;
    unordered_map<int, set<int>> subs;
    
    int dfs(int id) {
        int res = imp[id];
        for (const auto& s : subs[id]) res += dfs(s);
        return res;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        imp.clear(); subs.clear();
        
        for (auto& emp : employees) {
            imp[emp->id] = emp->importance;
            for (int sub : emp->subordinates) subs[emp->id].insert(sub);
        }
        
        if (imp.count(id) == 0) return 0;
        
        return dfs(id);
    }
};

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

// https://leetcode.com/problems/maximum-total-importance-of-roads/?envType=daily-question&envId=2024-06-28
// Graph + Sorting + Greedy

class Solution {
public:
    #define ll long long
    #define pii pair<int, int>

    long long maximumImportance(int n, vector<vector<int>>& roads) {
         // Build indegree array
        vector<int> indegree(n, 0);
        for (auto& road : roads) {
            indegree[road[0]]++;
            indegree[road[1]]++;
        }
        
        // Sort nodes by indegree
        vector<pii> indegree_pairs;
        for (int i = 0; i < n; ++i) {
            indegree_pairs.push_back({indegree[i], i});
        }
        sort(indegree_pairs.begin(), indegree_pairs.end());
        
        // Assign values based on sorted indegree
        vector<int> values(n);
        for (int i = 0; i < n; i++) {
            values[indegree_pairs[i].second] = i + 1; 
        }
        
        // Calculate maximum importance
        ll max_importance = 0;
        for (auto& road : roads) {
            int city1 = road[0], city2 = road[1];
            max_importance += values[city1] + values[city2];
        }
        
        return max_importance;
    }
};

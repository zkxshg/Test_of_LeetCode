// https://leetcode.com/problems/build-a-matrix-with-conditions/?envType=daily-question&envId=2024-07-21
// TopoSort + matrix (30min)

class Solution {
public:
    vector<int> topoSort(int k, vector<vector<int>>& conditions) {
        vector<int> order(k);
        vector<int> indegree(k + 1, 0); // k+1 to handle 1-based indexing
        
        // Calculate in-degrees
        for (auto& cond : conditions) {
            int above = cond[0], below = cond[1];
            indegree[below]++;
        }
        
        // Perform topological sort
        queue<int> q;
        for (int i = 1; i <= k; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int index = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order[index++] = node;
            
            for (auto& cond : conditions) {
                if (cond[0] == node) {
                    int below = cond[1];
                    indegree[below]--;
                    if (indegree[below] == 0) {
                        q.push(below);
                    }
                }
            }
        }

        if (index != k) {
            return vector<int>();
        }
        
        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Initialize
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        
        // TopoSort the row and col individually
        vector<int> rowOrder = topoSort(k, rowConditions);
        if (rowOrder.empty()) {
            return vector<vector<int>>();
        }

        vector<int> colOrder = topoSort(k, colConditions);
        if (colOrder.empty()) {
            return vector<vector<int>>();
        }

        // for (int i : rowOrder) cout << i << ","; cout << endl;
        // for (int i : colOrder) cout << i << ","; cout << endl;

        vector<pair<int, int> > indexes(k);
        for (int i = 0; i < k; i++) {
            indexes[rowOrder[i] - 1].first = i;
            indexes[colOrder[i] - 1].second = i;
        }
        // for (auto& pii : indexes) cout << pii.first << ":" << pii.second << endl;  
        
        // Fill the matrix
        for (int i = 0; i < k; i++) {
            int row = indexes[i].first, col = indexes[i].second;
            matrix[row][col] = i + 1;
        }
        
        return matrix;
    }
};

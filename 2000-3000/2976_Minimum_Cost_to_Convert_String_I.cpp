// https://leetcode.com/problems/minimum-cost-to-convert-string-i/?envType=daily-question&envId=2024-07-27
// Graph-Floyd-Warshall Algo

class Solution {
public:
    #define ll long long

    void print2D(vector<vector<long long>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == LLONG_MAX) {
                    cout << "I ";
                } else {
                    cout << matrix[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // Initialize cost matrix
        const int alphabetSize = 26; // lowercase English letters
        vector<vector<ll>> costMatrix(alphabetSize, vector<ll>(alphabetSize, LLONG_MAX));
        for (int i = 0; i < 26; i++) costMatrix[i][i] = 0;
        
        // Add cost to cost matrix
        int n = original.size();
        for (int i = 0; i < n; ++i) {
            int c1 = original[i] - 'a';
            int c2 = changed[i] - 'a';
            int costVal = cost[i];
            costMatrix[c1][c2] = min(costMatrix[c1][c2], (ll)costVal);
        }
        
        // Floyd-Warshall algorithm to compute shortest paths
        for (int k = 0; k < alphabetSize; ++k) {
            for (int i = 0; i < alphabetSize; ++i) {
                for (int j = 0; j < alphabetSize; ++j) {
                    if (costMatrix[i][k] != LLONG_MAX && costMatrix[k][j] != LLONG_MAX) {
                        costMatrix[i][j] = min(costMatrix[i][j], costMatrix[i][k] + costMatrix[k][j]);
                    }
                }
            }
        }
        // print2D(costMatrix);

        // Calculate minimum cost to convert source to target
        ll minCost = 0;
        int len = source.size();
        for (int i = 0; i < len; ++i) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';
            if (costMatrix[s][t] == LLONG_MAX) {
                return -1; // Conversion is not possible
            }
            minCost += costMatrix[s][t];
        }
        
        return minCost;
    }
};

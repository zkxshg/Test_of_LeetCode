// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/?envType=daily-question&envId=2024-07-20
// Math + Greedy (3h)

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        
        // Min-heaps of row and col sums
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> rowHeap, colHeap;
        
        // Initialize the heaps
        for (int i = 0; i < m; ++i) rowHeap.push({rowSum[i], i});
        for (int j = 0; j < n; ++j) colHeap.push({colSum[j], j});
 
        // Initialize the result matrix
        vector<vector<int>> res(m, vector<int>(n, 0));
        
        // Build the matrix
        while (!rowHeap.empty() && !colHeap.empty()) {
            auto [rowValue, rowIndex] = rowHeap.top();
            auto [colValue, colIndex] = colHeap.top();
            int fillAmount = min(rowValue, colValue);

            res[rowIndex][colIndex] = fillAmount;

            colHeap.pop();
            rowHeap.pop();
            if (rowValue > colValue) {
                rowHeap.push({rowValue - fillAmount, rowIndex});
            }
            else if (rowValue < colValue) {
                colHeap.push({colValue - fillAmount, colIndex});
            } 
        }
        
        return res;
    }
};

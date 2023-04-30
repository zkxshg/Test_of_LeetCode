// https://leetcode.com/problems/n-queens/
// backtracking
class Solution {
public:
    vector<vector<string>> sols;
    int N;
    
    void nextR(int row, vector<string> cboard, vector<vector<int> > board) {
        vector<int>& R = board[row];
        
        for (int i = 0; i < N; i++) {
            if (!R[i]) {
                vector<string> nc = cboard; nc[row][i] = 'Q';
                
                if (row == N - 1) sols.push_back(nc);
                else {
                    vector<vector <int>> nB = board;
                    for (int j = row + 1; j < N; j++) {
                        nB[j][i] = 1;
                        if (j - row < N - i) nB[j][i + j - row] = 1;
                        if (j - row <= i) nB[j][i - j + row] = 1;
                    }
                    nextR(row + 1, nc, nB);
                }
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        if (n == 1) return {{"Q"}};
        else if (n < 4) return {};
        
        sols.clear(); N = n;
        
        string ini = ""; for (int i = 0; i < N; i++) ini += '.';
        
        vector<string> cboard(N, ini);
        vector<vector<int> > board(N, vector<int>(N));
            
        nextR(0, cboard, board);
        
        return sols;
    }
};

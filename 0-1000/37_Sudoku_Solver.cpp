// https://leetcode.com/problems/sudoku-solver/
// hash table + backtracking

class Solution {
public:
    int whichGrid(int x, int y) {
        if (x <= 2 && y <= 2) return 1;
        else if (x <= 2 && y <= 5) return 2;
        else if (x <= 2 && y <= 8) return 3;
        else if (x <= 5 && y <= 2) return 4;
        else if (x <= 5 && y <= 5) return 5;
        else if (x <= 5 && y <= 8) return 6;
        else if (x <= 8 && y <= 2) return 7;
        else if (x <= 8 && y <= 5) return 8;
        return 9;
    }
    
    bool backtrack(int x, int y, vector<vector<char>>& B,
                   unordered_map<int, unordered_map<int, int>>& R,
                   unordered_map<int, unordered_map<int, int>>& C,
                   unordered_map<int, unordered_map<int, int>>& G
                  ) {
        
        if (x > 8 || y > 8) return true;
        
        int nex = x, ney = y;
        if (x < 8) nex++;
        else { 
            ney++; nex = 0; 
        }
        
        if (B[x][y] != '.') return backtrack(nex, ney, B, R, C, G);
        
        for (int i = 1; i <= 9; i++) {
            if (!R[x][i] && !C[y][i] && !G[whichGrid(x, y)][i]) {
                R[x][i] = 1; C[y][i] = 1; G[whichGrid(x, y)][i] = 1; 
                B[x][y] = '0' + i;
                
                if (backtrack(nex, ney, B, R, C, G)) return true;
                
                R[x][i] = 0; C[y][i] = 0; G[whichGrid(x, y)][i] = 0;
                B[x][y] = '.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_map<int, int>> rows;
        unordered_map<int, unordered_map<int, int>> cols;
        unordered_map<int, unordered_map<int, int>> grids;
        
        // recond current nums 
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    rows[i][board[i][j] - '0'] = 1;
                    cols[j][board[i][j] - '0'] = 1;
                    grids[whichGrid(i, j)][board[i][j] - '0'] = 1;
                }
                // cout << i << "," << j << "=" << whichGrid(i, j) << endl;
            }
            
        }
        
        bool res = backtrack(0, 0, board, rows, cols, grids);
        
        // cout << res << endl;
    }
};

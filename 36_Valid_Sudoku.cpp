// https://leetcode.com/problems/valid-sudoku/
// hash table

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
    
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_map<int, int>> rows;
        unordered_map<int, unordered_map<int, int>> cols;
        unordered_map<int, unordered_map<int, int>> grids;
        
         // recond current nums 
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (rows[i][board[i][j] - '0']) return false;
                    else rows[i][board[i][j] - '0'] = 1;
                    
                    if (cols[j][board[i][j] - '0']) return false;
                    else cols[j][board[i][j] - '0'] = 1;
                    
                    if (grids[whichGrid(i, j)][board[i][j] - '0']) return false;
                    else grids[whichGrid(i, j)][board[i][j] - '0'] = 1;
                }
            }
        }
        
        return true;
    }
};

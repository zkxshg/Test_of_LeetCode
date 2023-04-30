// https://leetcode.com/problems/battleships-in-a-board/
// BFS

class Solution {
public:
    int m, n;
    vector<vector<int> > sea;
    
    void expand(vector<vector<char>>& grid, int i, int j, int num) {
        sea[i][j] = num;
        
        if (i > 0 && !sea[i - 1][j] && grid[i - 1][j] == 'X') expand(grid, i - 1, j, num);
        
        if (j > 0 && !sea[i][j - 1] && grid[i][j - 1] == 'X') expand(grid, i, j - 1, num);
        
        if (i < m - 1 && !sea[i + 1][j] && grid[i + 1][j] == 'X') expand(grid, i + 1, j, num);
        
        if (j < n - 1 && !sea[i][j + 1] && grid[i][j + 1] == 'X') expand(grid, i, j + 1, num);
    }
    
    int countBattleships(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        
        sea.resize(m, vector<int>(n));
        
        int cnt = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!sea[i][j] && board[i][j] == 'X') {
                    expand(board, i, j, cnt);
                    cnt++;
                }
            }       
        }
        
        return cnt - 1;
    }
};

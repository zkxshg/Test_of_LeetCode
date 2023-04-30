// array
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int len = board.size(), wid = board[0].size();
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) board[i][j] = live(board, i, j);
        }
        //return;
        
         for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (board[i][j] > 1) board[i][j] = 0;
                else if (board[i][j] < 0) board[i][j] = 1;
            }
        }
    }
    
    int live(vector<vector<int>>& b, int x, int y) {
        int ones = 0, len = b.size(), wid = b[0].size();
        
        if (x > 0) {
            if (b[x - 1][y] > 0) ones++;
            if (y > 0 && b[x - 1][y - 1] > 0) ones++;
            if (y < wid - 1 && b[x - 1][y + 1] > 0) ones++;
        }
        
        if (y > 0) {
            if (b[x][y - 1] > 0) ones++;
            if (x < len - 1 && b[x + 1][y - 1] > 0) ones++;
        }
        
        if (x < len - 1) {
            if (b[x + 1][y] > 0) ones++;
            if (y < wid - 1 && b[x + 1][y + 1] > 0) ones++;
        }
        
        if (y < wid - 1 && b[x][y + 1] > 0) ones++;

        if (ones < 2 && b[x][y] > 0) return 4;
        if (ones == 2) return b[x][y];
        if (ones > 3 && b[x][y] > 0) return 4;
        if (ones == 3) {
            if (b[x][y] > 0) return 1;
            else return -1;
        }
        
        return 0;
    }
};

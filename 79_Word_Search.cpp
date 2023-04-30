// DFS; Can be improved by hash stack
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int len = board.size(), wid = board[0].size();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (board[i][j] != word[0]) continue;
                vector<vector<bool>> ifCheck(len, vector<bool>(wid, false));
                if (wordCheck(board, ifCheck, word, i, j)) return true;
            }
        }
        return false;
    }
    
    bool wordCheck(vector<vector<char>>& board, vector<vector<bool>>& ifCheck, string word, int x, int y) {
        if (word.size() == 0) return true;
        
        if (board[x][y] != word[0]) return false;
        else if (word.size() == 1) return true;
        
        ifCheck[x][y] = true;
        
        int len = board.size(), wid = board[0].size(); 
        if (x < len - 1 && !ifCheck[x+1][y]) {
            if (wordCheck(board, ifCheck, word.substr(1), x + 1, y)) return true;
        }
        
        if (x > 0 && !ifCheck[x-1][y]) {
            if (wordCheck(board, ifCheck, word.substr(1), x - 1, y)) return true;
        }
        
        if (y < wid - 1 && !ifCheck[x][y+1]) {
            if (wordCheck(board, ifCheck, word.substr(1), x, y + 1)) return true;
        }
        
        if (y > 0 && !ifCheck[x][y-1]) {
            if (wordCheck(board, ifCheck, word.substr(1), x, y - 1)) return true;
        }
        
        ifCheck[x][y] = false;
        return false;
    }
};

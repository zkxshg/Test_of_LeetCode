// https://leetcode.com/problems/surrounded-regions/
// Union Find: O->F || O->X || F-> O
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O')
                dfs(board, i, 0);
        }
        
        for(int i = 0; i < m; i++) {
            if(board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }
        
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O')
                dfs(board, 0, j);
        }
        
        for(int j = 0; j < n; j++) {
            if(board[m - 1][j] == 'O')
                dfs(board, m - 1, j);
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'P')
                    board[i][j] = 'O';
            }
        }
        
    }
    
    void dfs(vector<vector<char>>& A, int x, int y) {
        if(x >= 0 && x < A.size() && y >= 0 && y < A[0].size() && A[x][y] == 'O') {
            A[x][y] = 'P';
            dfs(A, x + 1, y);
            dfs(A, x, y + 1);
            dfs(A, x - 1, y);
            dfs(A, x, y - 1);
        } else return;
    }
};

// boolean
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int len = board.size();     if (len == 0) return;
        int wid = board[0].size();  if (wid == 0) return;
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if(board[i][j] != 'X' && notflipped(board, i, j)) board[i][j] = 'F';
            } 
        }
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if(board[i][j] == 'T') board[i][j] = 'X';
            } 
        }
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if(board[i][j] == 'F') board[i][j] = 'O';
            } 
        }
    }
    

    bool notflipped(vector<vector<char>>& board, int i, int j) {
        
        int len = board.size(), wid = board[0].size(); 
        
        if (board[i][j] == 'X' || board[i][j] == 'T') return false;
        if (board[i][j] == 'F') return true;
        
        if (i <= 0 || j <= 0 || i >= len - 1 || j >= wid - 1) return true;
        else {
            bool flip = true;
            board[i][j] = 'T';
            
            if (i < len - 1 && notflipped(board, i+1, j)) flip = false;
            if (j < wid - 1 && notflipped(board, i, j+1)) flip = false;
            if (i > 0 && notflipped(board, i-1, j)) flip = false;
            if (j > 0 && notflipped(board, i, j-1)) flip = false;

            if (!flip) {
                board[i][j] = 'F'; 
                return true; 
            } 
        }
       
        return false;
    }
};

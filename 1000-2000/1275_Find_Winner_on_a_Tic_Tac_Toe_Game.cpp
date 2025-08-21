// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
// array

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> row(3); vector<int> col(3); vector<int> dia(2);
        
        int n = moves.size(), pos = 0;
        while (pos < n) {
            vector<int>& v = moves[pos];
            row[v[0]]++; if (row[v[0]] >= 3) return "A";
            col[v[1]]++; if (col[v[1]] >= 3) return "A";
            
            if (v[0] == v[1]) {
                dia[0]++; if (dia[0] >= 3) return "A";
            }
            
            if (v[0] + v[1] == 2) {
                dia[1]++; if (dia[1] >= 3) return "A";
            }
            
            pos++;
            
            if (pos >= n) break;
            
            v = moves[pos];
            
            row[v[0]]--; if (row[v[0]] <= -3) return "B";
            col[v[1]]--; if (col[v[1]] <= -3) return "B";
            
            if (v[0] == v[1]) {
                dia[0]--; if (dia[0] <= -3) return "B";
            }
            
            if (v[0] + v[1] == 2) {
                dia[1]--; if (dia[1] <= -3) return "B";
            }
            
            pos++;
        }
        
        if (n == 9) return "Draw";
        
        return "Pending";
    }
};

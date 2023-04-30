//DP
class Solution {
public:
    string pushDominoes(string dominoes) {
        int len = dominoes.size(); if (len < 2) return dominoes;
        
        int deltaNum = 1;
        while (deltaNum > 0) {
            deltaNum = 0;
            string temp = dominoes;
            
            if (dominoes[0] == '.' && dominoes[1] != '.') {
                if (dominoes[1] == 'L') {
                    temp[0] = 'L';
                    deltaNum++;
                }
            }
            
            if (dominoes[len - 1] == '.' && dominoes[len - 2] != '.') {
                if (dominoes[len - 2] == 'R') {
                    temp[len - 1] = 'R';
                    deltaNum++;
                } 
            }
            
            for (int i = 1; i < len - 1; i++) {
                if (dominoes[i] == '.') {
                    if (dominoes[i - 1] == 'L') {
                        if (dominoes[i + 1] == 'L') {
                            temp[i] = 'L'; 
                            deltaNum++;
                        }
                    }
                    else if (dominoes[i - 1] == 'R') {
                        if (dominoes[i + 1] != 'L') {
                            temp[i] = 'R';
                            deltaNum++;
                        }
                    }
                    else if (dominoes[i + 1] == 'L') {
                        temp[i] = 'L'; 
                        deltaNum++;
                    }
                }
            }
            dominoes = temp;
        }
        return dominoes;
    }
};

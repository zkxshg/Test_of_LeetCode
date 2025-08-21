// DP
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size(); if (n < 3) return *max_element(stones.begin(), stones.end()); 
        
        vector<vector<int> > rest(n, vector<int>(n));
        for (int i = 0; i < n; i++) rest[i][i] = stones[i];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) rest[j][j + i] = rest[j][j + i - 1] + stones[j + i];
        }
        
        vector<vector<int> > M(n, vector<int>(n)); 
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) 
                M[j][j + i] = max(rest[j][j + i - 1] - M[j][j + i - 1], 
                                  rest[j + 1][j + i] - M[j + 1][j + i]); 
        }
        
        return M[0][n - 1];    
    }
};

// A* algo 1
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size(); if (n < 3) return *max_element(stones.begin(), stones.end()); 
        
        int rest = 0;
        for (int i : stones) rest += i;
        
        return score(stones, rest, 0, n - 1);    
    }
    
    int score(vector<int>& stones, int rest, int st, int en) {
        int n = en - st + 1; 
        if (n == 1) return 0;
        if (n == 2) return max(stones[st], stones[en]);
        
        int As = 0, Bs = 0;
        while (st < en) {
            // Alice
            int ls = (rest - stones[st]) - optScore(stones, rest - stones[st], st + 1, en);
            int rs = (rest - stones[en]) - optScore(stones, rest - stones[en], st, en - 1);
            
            if (ls > rs) {
                As += rest - stones[st];
                rest -= stones[st];
                st++;
            }
            else {
                As += rest - stones[en];
                rest -= stones[en];
                en--;
            }
            
            // Bob 
            if (st == en) break;
            
            ls = (rest - stones[st]) - optScore(stones, rest - stones[st], st + 1, en);
            rs = (rest - stones[en]) - optScore(stones, rest - stones[en], st, en - 1);
            
            if (ls > rs) {
                Bs += rest - stones[st];
                rest -= stones[st];
                st++;
            }
            else {
                Bs += rest - stones[en];
                rest -= stones[st];
                en--;
            }
            //return ls;
        }
        
        return As - Bs;
    }
    
    int optScore(vector<int>& stones, int rest, int st, int en) {
        int n = en - st + 1; 
        if (n == 1) return 0;
        if (n == 2) return max(stones[st], stones[en]);
        
        int sco = 0;
        
        if (stones[st] > stones[en]) {
            sco = rest - stones[en];
            return sco - optScore(stones, rest - stones[en], st, en - 1);
        }
        
        sco = rest - stones[st];
        return sco - optScore(stones, rest - stones[st], st + 1, en);   
    }
};

// A* algo 2
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size(); if (n < 3) return *max_element(stones.begin(), stones.end()); 
        
        int rest = 0;
        for (int i : stones) rest += i;
        
        return score(stones, rest, 0, n-1);    
    }
    
    int score(vector<int>& stones, int rest, int st, int en) {
        int n = en - st + 1; 
        if (n == 1) return 0;
        if (n == 2) return max(stones[st], stones[en]);
        
        int As = 0, Bs = 0;
        while (st < en) {
            // Alice
            int ls = (rest - stones[st]) - nextScore(stones, rest - stones[st], st + 1, en);
            int rs = (rest - stones[en]) - nextScore(stones, rest - stones[en], st, en - 1);
            
            if (ls > rs) {
                As += rest - stones[st];
                rest -= stones[st];
                st++;
            }
            else {
                As += rest - stones[en];
                rest -= stones[en];
                en--;
            }
            
            // Bob 
            if (st == en) break;
            
            ls = (rest - stones[st]) - nextScore(stones, rest - stones[st], st + 1, en);
            rs = (rest - stones[en]) - nextScore(stones, rest - stones[en], st, en - 1);
            
            if (ls > rs) {
                Bs += rest - stones[st];
                rest -= stones[st];
                st++;
            }
            else {
                Bs += rest - stones[en];
                rest -= stones[st];
                en--;
            }
        }
        
        return As - Bs;
    }
    
    int nextScore(vector<int>& stones, int rest, int st, int en) {
        int n = en - st + 1; 
        if (n == 1) return 0;
        if (n == 2) return max(stones[st], stones[en]);
        
        return max(rest - stones[st], rest - stones[en]);
        
    }
};

// recursive
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size(); if (n < 3) return *max_element(stones.begin(), stones.end()); 
        
        int rest = 0;
        for (int i : stones) rest += i;
        
        return score(stones, rest, 0, n - 1);    
    }
    
    int score(vector<int>& stones, int rest, int st, int en) {
        int n = en - st + 1; 
        if (n == 1) return 0;
        if (n == 2) return max(stones[st], stones[en]);
        
        int ls = (rest - stones[st]) - score(stones, rest - stones[st], st + 1, en);
        int rs = (rest - stones[en]) - score(stones, rest - stones[en], st, en - 1);
        
        return max(ls, rs);
    }
};

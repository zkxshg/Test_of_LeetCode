// https://leetcode.com/problems/water-and-jug-problem/
// math
class Solution {
public:
    int j1c, j2c, tc; 
    
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        j1c = jug1Capacity; j2c = jug2Capacity; tc = targetCapacity;
        return (j1c + j2c >= tc) && (tc % (gcd(j1c, j2c)) == 0);
    }
};

// BFS
class Solution {
public:
    int j1c, j2c, tc; 
    unordered_map<int, unordered_map<int, int>> rec;
    
    vector<pair<int, int> > dfs(int j1, int j2) {
        vector<pair<int, int> > nex;
        // 1-1. fill j1 
        if (j1 < j1c && !rec[j1c][j2]) {
            rec[j1c][j2]++; nex.push_back({j1c, j2});
        }
        
        // 1-2. fill j2
        if (j2 < j2c && !rec[j1][j2c]) {
            rec[j1][j2c]++; nex.push_back({j1, j2c});
        }
        
        //2-1. empty j1
        if (j1 > 0 && !rec[0][j2] ) {
            rec[0][j2]++; nex.push_back({0, j2});
        }
        
        //2-2. empty j2
        if (j2 > 0 && !rec[j1][0]) {
            rec[j1][0]++; nex.push_back({j1, 0});
        }
        
        // 3-1. pour j1 into j2
        if (j2 < j2c && j1 > 0) {
            
            if (j1 + j2 <= j2c) {  // case 1: not full
                if (!rec[0][j1 + j2]) {
                    rec[0][j1 + j2]++; nex.push_back({0, j1 + j2});
                }
            }
            else {  // case 2: full
                if (!rec[j1 - (j2c - j2)][j2c]) {
                    rec[j1 - (j2c - j2)][j2c]++; nex.push_back({j1 - (j2c - j2), j2c});
                }
            }
        }

        // 3-2. pour j2 into j1
        if (j1 < j1c && j2 > 0) {

            if (j1 + j2 <= j1c) {  // case 1: not full
                if (!rec[j1 + j2][0]) {
                    rec[j1 + j2][0]++; nex.push_back({j1 + j2, 0});
                }
            }
            else {  // case 2: full
                if (!rec[j1c][j2 - (j1c - j1)]) {
                    rec[j1c][j2 - (j1c - j1)]++; nex.push_back({j1c, j2 - (j1c - j1)});
                }
            }
        }
        
        return nex;
    }
    
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        j1c = jug1Capacity; j2c = jug2Capacity; tc = targetCapacity;
        rec.clear();
        
        // if (j1c == 104579 && j2c == 104593 && tc == 12444) return true;
        vector<pair<int, int> > bfs; 
        bfs.push_back({0, 0}); rec[0][0]++;
        
        bool res = false;
        while (!res && !bfs.empty()) {
            vector<pair<int, int> > tem;
            
            for (auto& p : bfs) {
                vector<pair<int, int> > nex = dfs(p.first, p.second);
                
                for (auto& p2 : nex) {
                    int j1 = p2.first, j2 = p2.second; 
                    
                    if (j1 == tc || j2 == tc || j1 + j2 == tc) return true;
                    else tem.push_back(p2);
                }   
            }
            
            bfs = tem;
        }
        
        return res;
    }
};

// DFS
class Solution {
public:
    int j1c, j2c, tc; 
    unordered_map<int, unordered_map<int, int>> rec;
    
    bool dfs(int j1, int j2) {
        // if (j1 < 0 || j2 < 0 || j1 > j1c || j2 > j2c) cout << j1 << ":" << j2 << endl;
        rec[j1][j2]++;
        
        if (j1 == tc || j2 == tc || j1 + j2 == tc) return true;
        
        // 1-1. fill j1 
        if (j1 < j1c && !rec[j1c][j2] && dfs(j1c, j2)) return true;
        
        // 1-2. fill j2
        if (j2 < j2c && !rec[j1][j2c] && dfs(j1, j2c)) return true;
        
        //2-1. empty j1
        if (j1 > 0 && !rec[0][j2] && dfs(0, j2)) return true;
        
        //2-2. empty j2
        if (j2 > 0 && !rec[j1][0] && dfs(j1, 0)) return true;
        
        // 3-1. pour j1 into j2
        if (j2 < j2c && j1 > 0) {
            
            if (j1 + j2 <= j2c) {  // case 1: not full
                if (!rec[0][j1 + j2] && dfs(0, j1 + j2)) return true;
            }
            else {  // case 2: full
                if (!rec[j1 - (j2c - j2)][j2c] && dfs(j1 - (j2c - j2), j2c)) return true;
            }
        }

        // 3-2. pour j2 into j1
        if (j1 < j1c && j2 > 0) {
            cout << j1 << ":" << j2 << endl;
            if (j1 + j2 <= j1c) {  // case 1: not full
                if (!rec[j1 + j2][0] && dfs(j1 + j2, 0)) return true;
            }
            else {  // case 2: full
                if (!rec[j1c][j2 - (j1c - j1)] && dfs(j1c, j2 - (j1c - j1)) ) return true;
            }
        }
        
        return false;
    }
    
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        j1c = jug1Capacity; j2c = jug2Capacity; tc = targetCapacity;
        rec.clear();
        
        // if (j1c == 104579 && j2c == 104593 && tc == 12444) return true;
        
        int j1 = 0, j2 = 0;
        bool res = dfs(j1, j2);
        return res;
    }
};

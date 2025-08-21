// https://leetcode.com/problems/min-cost-to-connect-all-points/
// prim 2 
class Solution {
public:
    int dist(vector<int>& a1, vector<int>& a2) {
        return abs(a1[0] - a2[0]) + abs(a1[1] - a2[1]);
    }
    
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(); 
        if (n < 2) return 0;
        if (n < 3) return dist(points[0], points[1]);
        
        unordered_map<int, vector<pair<int, int> > > path;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = dist(points[i], points[j]);
                path[i].push_back(make_pair(d, j));
                path[j].push_back(make_pair(d, i));
            }
            sort(path[i].begin(), path[i].end(), cmp);
            // for (pair<int, int>& j : path[i]) cout << j.first << ":" << j.second << ",";
            // cout << endl;
        }
        
        int res = 0;
        
        unordered_map<int, int> visited;
        
        vector<int> V = {0}; visited[0]++;
        
        while (V.size() < n) {
            int nex = -1, nexP = 0, dis = 20000001;
            
            for (int i : V) {
                while (!path[i].empty() && visited[path[i].back().second]) path[i].pop_back();
                
                if (path[i].empty()) continue;
                
                if (path[i].back().first < dis) {
                    nex = path[i].back().second; nexP = i; dis = path[i].back().first;
                }
            }
            
            res += dis; V.push_back(nex); visited[nex]++; path[nexP].pop_back();
            
            // cout << nex << endl;
        }
       
        return res;
    }
};

// prim algo
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int len = points.size(); 
        if (len < 2) return 0;
        if (len < 3) return dist(points[0], points[1]);
        
        int maxVal = 2 * pow(10, 6) + 1;
        vector<vector<int>> distM(len, vector<int>(len, maxVal));
        
        for (int i = 0; i < len; i++) {
            for (int j = 1; j < len; j++) {
                if (i != j) distM[i][j] = dist(points[i], points[j]);
            }
        }
        
        int * minVals = new int[len];
        int * minValsPos = new int[len];
        bool * ifCut = new bool[len];
        
        for (int i = 0; i < len; i++) {
            minValsPos[i] = 0;
            minVals[i] = distM[0][i];
            ifCut[i] = false;
        }
        ifCut[0] = true;
        
        int totalDist = 0;
        
        for (int i = 1; i < len; i++) {
            
            int minN = -1, minDist = maxVal;
            for (int j = 1; j < len; j++) {
                if (!ifCut[j] && minVals[j] < minDist) {
                    minN = j;
                    minDist = minVals[j];
                }
            }
            
            for (int j = 1; j < len; j++) {
                if (j != minN && !ifCut[j] && distM[minN][j] < minVals[j]) minVals[j] = distM[minN][j];
            }
            
            totalDist += minDist;
            ifCut[minN] = true;
        }
        
        return totalDist;
        
    }
    
    int dist(vector<int> a1, vector<int> a2) {
        return abs(a1[0] - a2[0]) + abs(a1[1] - a2[1]);
    }
};

// false prim algo
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int len = points.size(); 
        if (len < 2) return 0;
        if (len < 3) return dist(points[0], points[1]);
        
        int maxVal = pow(10, 6) + 1;
        vector<vector<int>> distM(len, vector<int>(len, maxVal));
        
        for (int i = 0; i < len; i++) {
            for (int j = 1; j < len; j++) {
                if (i != j) distM[i][j] = dist(points[i], points[j]);
            }
        }
        
        vector<int> set;
        set.push_back(0);
        
        int * minVals = new int[len];
        int * minValsPos = new int[len];
        for (int i = 0; i < len; i++) {
            minValsPos[i] = min_element(distM[i].begin(), distM[i].end()) - distM[i].begin();
            minVals[i] = distM[i][minValsPos[i]];
        }
        
        
        int totalDist = 0;
        while (set.size() < len) {
            int minLen = maxVal, minPos = -1, minRow = -1;
            for (int p : set) {
                int temPos = minValsPos[p];
                int minP = minVals[p];
                
                if (minP < minLen) {
                    minLen = minP;
                    minPos = temPos;
                    minRow = p;
                }
            }
            
            set.push_back(minPos);
            totalDist += minLen;
            
            for (int i = 0; i < len; i++) distM[i][minPos] = maxVal;
            
            for (int i : set) {
                if (minValsPos[i] == minPos) {
                    minValsPos[i] = min_element(distM[i].begin(), distM[i].end()) - distM[i].begin();
                    minVals[i] = distM[i][minValsPos[i]];
                }    
            }
            
            if (find(set.begin(), set.end(), minValsPos[minPos]) != set.end()) {
                minValsPos[minPos] = min_element(distM[minPos].begin(), distM[minPos].end())
                    - distM[minPos].begin();
                minVals[minPos] = distM[minPos][minValsPos[minPos]];
            }
            
        }
        
        return totalDist;
        
    }
    
    int dist(vector<int> a1, vector<int> a2) {
        return abs(a1[0] - a2[0]) + abs(a1[1] - a2[1]);
    }
};

// pair + prim
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int len = points.size(); 
        if (len < 2) return 0;
        if (len < 3) return dist(points[0], points[1]);
        
        int maxVal = 2 * pow(10, 6) + 1;
        vector<vector<int>> distM(len, vector<int>(len, maxVal));
        
        for (int i = 0; i < len; i++) {
            for (int j = 1; j < len; j++) {
                if (i != j) distM[i][j] = dist(points[i], points[j]);
            }
        }
        
        vector<int> set;
        vector<bool> ifCut(len, false);
        
        set.push_back(0);
        ifCut[0] = true;
        
        vector<vector<pair<int, int>>> minVals;
        for (int i = 0; i < len; i++) {
            vector<pair<int, int> > rowVals;
            for (int j = 1; j < len; j++) rowVals.push_back(make_pair(distM[i][j],j));
            
            sort(rowVals.begin(), rowVals.end());
            minVals.push_back(rowVals);
        }
        
        vector<int> minValsPos(len);
        
        int totalDist = 0;
        while (set.size() < len) {
            int minLen = maxVal, minPos = -1;
            for (int p : set) {
                while (ifCut[minVals[p][minValsPos[p]].second])
                    minValsPos[p]++;
                
                int temPos = minVals[p][minValsPos[p]].second;
                int minP = minVals[p][minValsPos[p]].first;
                
                if (minP < minLen) {
                    minLen = minP;
                    minPos = temPos;
                }
            }
            
            set.push_back(minPos);
            totalDist += minLen;
            ifCut[minPos] = true;
            
            if (find(set.begin(), set.end(), minVals[minPos][minValsPos[minPos]].second) != set.end()) 
                minValsPos[minPos]++;
            
        }
        
        return totalDist;
        
    }
    
    int dist(vector<int> a1, vector<int> a2) {
        return abs(a1[0] - a2[0]) + abs(a1[1] - a2[1]);
    }
};

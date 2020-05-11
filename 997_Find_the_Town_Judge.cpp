// graph
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int len = trust.size();
        if (len < N - 1) return -1;
        else if (N == 1) return 1;
        unordered_map<int, int> trustD;
        for (int i = 0; i < len; i++) {
            trustD[trust[i][0]] = -1;
            if (trustD[trust[i][1]] < 0) continue;
            trustD[trust[i][1]]++;
        }
        for (int i = 1; i < N + 1; i++) {
            if (trustD[i] == N - 1) return i; 
        }
        return -1;
        
    }
};

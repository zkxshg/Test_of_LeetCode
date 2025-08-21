// transform preferences to favos
class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        if (n <= 2) return 0;
        
        vector<vector<int>> favos(n);
        for (vector<int> pair : pairs) {
            int i = pair[0], j = pair[1];
            
            int jpos = find(preferences[i].begin(), preferences[i].end(), j) - preferences[i].begin();
            if (jpos != 0) {
                for (int k = 0; k < jpos; k++) favos[i].push_back(preferences[i][k]);
            }
            
            int ipos = find(preferences[j].begin(), preferences[j].end(), i) - preferences[j].begin();
            if (ipos != 0) {
                for (int k = 0; k < ipos; k++) favos[j].push_back(preferences[j][k]);
            }
        }
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (favos[i].size() > 0) {
                for (int favo : favos[i]) {
                    if (find(favos[favo].begin(), favos[favo].end(), i) != favos[favo].end()) {
                        result++;
                        break;
                    }
                }
            }
        }
        
        return result;
    }
};

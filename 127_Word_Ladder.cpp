// https://leetcode.com/problems/word-ladder/
// Dijkstra + BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto find1 = find(wordList.begin(), wordList.end(), endWord);
        if (find1 == wordList.end()) return 0;
        int pos = find1 - wordList.begin();
        
        int n = wordList.size(), big = 10001;
        
        vector<vector<bool> > oneDif(n, vector<bool>(n, false));
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (ifTrans(wordList[i], wordList[j])) {
                    oneDif[i][j] = true; oneDif[j][i] = true;
                }
            }
        }
            
        vector<int> dist(n, big);
        vector<int> Q(n); for (int i = 0; i < n; i++) Q[i] = i;

        auto find2 = find(wordList.begin(), wordList.end(), beginWord);
        if (find2 != wordList.end()) {
            int pos2 = find2 - wordList.begin();
            Q.erase(Q.begin() + pos2);
        }
        
        for (int i : Q) {
            if (ifTrans(beginWord, wordList[i])) dist[i] = 1;
        }

        int cou = 0;
        while (!Q.empty() && dist[pos] >= big && cou <= n) {
            int minP = -1, minV = big;
            
            for (int i : Q) {
                if (dist[i] < minV) {
                    minP = i; minV = dist[i];
                }
            }
            if (minP < 0) return 0;
            
            Q.erase(find(Q.begin(), Q.end(), minP));
            
            for (int i : Q) {
                if (oneDif[minP][i]) dist[i] = min(dist[i], minV + 1); 
            }
                 
            cou++;
        }

        if (cou > n) return 0;
        return dist[pos] + 1;
    }
    
    bool ifTrans(string& beginWord, string& endWord) {
        int dif = 0, len = beginWord.size();
        for (int i = 0; i < len; i++) {
            if (beginWord[i] != endWord[i]) dif++;
            if (dif > 1) return false;
        }
        return true;
    }
};

// https://leetcode.com/problems/word-ladder-ii/
// BFS + hash map

class Solution {
public:
    bool ifTrans(string& beginWord, string& endWord) {
        int dif = 0, len = beginWord.size();
        for (int i = 0; i < len; i++) {
            if (beginWord[i] != endWord[i]) dif++;
            if (dif > 1) return false;
        }
        return true;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), big = 10001;
        
        // Search the endWord
        int pos = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
        if (pos >= n) return {};
        
        // Rec if word can reach each other 
        vector<vector<bool> > oneDif(n, vector<bool>(n, false));
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (ifTrans(wordList[i], wordList[j])) {
                    oneDif[i][j] = true; oneDif[j][i] = true;
                }
            }
        }
        
        vector<int> dist(n, big); // Dist from begin to  word
        set<int> Q; for (int i = 0; i < n; i++) Q.insert(i); // Candidates
        
        // Search if beginWord in list 
        auto find2 = find(wordList.begin(), wordList.end(), beginWord);
        if (find2 != wordList.end()) Q.erase(find2 - wordList.begin());

        unordered_map<string, vector<string> > pre;
        
        for (const auto &i : Q) {
            if (ifTrans(beginWord, wordList[i])) {
                dist[i] = 1;
                pre[wordList[i]].push_back(beginWord);
            }
        }
        
        int cou = 0;
        while (!Q.empty() && cou <= n) {
            int minP = -1, minV = big;
            
            for (const auto &i : Q) {
                if (dist[i] < minV) {
                    minP = i; minV = dist[i];
                }
            } 
            if (minP < 0) break;
            
            Q.erase(minP);
            
            for (const auto &i : Q) {
                if (oneDif[minP][i] && dist[i] >= minV + 1) {
                    if (dist[i] > minV + 1) {
                        dist[i] = minV + 1; 
                        pre[wordList[i]].clear();
                    }
                    
                    pre[wordList[i]].push_back(wordList[minP]);                                     
                } 
            }
                 
            cou++;
        }
        
        if (dist[pos] > n) return {};
        
        vector<vector<string>> res; res.push_back({endWord});
        
        for (int i = 0; i < dist[pos]; i++) {
            vector<vector<string>> tem;
            
            for (auto& v : res) {
                for (string& s : pre[v.back()]) {
                    vector<string> vs = v;
                    vs.push_back(s);
                    tem.push_back(vs);
                } 
            }
            
            if (tem.empty()) break;
            res = tem;
            
            // for (auto& v : res) {
            //     for (auto& s : v) cout << s << ","; cout << ";\n";
            // }
        }
        
        for (auto& v : res) reverse(v.begin(), v.end());
        return res;
    }
};

// https://leetcode.com/problems/open-the-lock/
// BFS

class Solution {
public:
    string addOne(string s, int pos) {
        int num = s[pos] - '0';
        num = num < 9 ? num + 1 : 0;
        
        s[pos] = num + '0';
        return s;
    }
    
    string subOne(string s, int pos) {
        int num = s[pos] - '0';
        num = num > 0 ? num - 1 : 9;
        
        s[pos] = num + '0';
        return s;
    }
    
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        
        unordered_map<string, int> DE;
        for (auto& s : deadends) DE[s]++;
        
        string bg = "0000";
        if (DE[bg]) return -1;
        
        vector<string> bfs; bfs.push_back(bg);
        unordered_map<string, int> vsted; vsted[bg]++;
        
        int step = 0; bool reach = false;
        while (!reach && !bfs.empty()) {
            step++;
            
            vector<string> tem;
            
            for (auto& s : bfs) {
                for (int i = 0; i < 4; i++) {
                    string addS = addOne(s, i);
                    
                    if (addS == target) {
                        reach = true; break;
                    }
                    
                    if (!vsted[addS] && !DE[addS]) {
                        tem.push_back(addS); vsted[addS]++;
                    }
                    
                    string subS = subOne(s, i);
                    
                    if (subS == target) {
                        reach = true; break;
                    }
                    
                    if (!vsted[subS] && !DE[subS]) {
                        tem.push_back(subS); vsted[subS]++;
                    }
                }
                
                if (reach) break;
            }
            
            bfs = tem;
        }
        
        if (reach) return step;
        
        return -1;
        
    }
};

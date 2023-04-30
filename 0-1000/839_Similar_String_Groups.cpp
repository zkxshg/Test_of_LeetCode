// https://leetcode.com/problems/similar-string-groups/description/
// Union-and-Find

class Solution {
public:
    unordered_map<int, int> U;
    
    int find(int a) {
        int ua = U[a];

        if (ua == a) return a;

        int pa = find(ua);
        U[a] = pa;

        return pa;
    }
    
    bool cmp(string& s1, string& s2) {
        int l = s1.size();
        int difNum = 0, dif1 = -1, dif2 = -1;

        for (int i = 0; i < l; i++) {
            if (s1[i] != s2[i]) difNum++;
            else continue;

            if (difNum > 2) break;
            else if (difNum == 1) dif1 = i;
            else if (difNum == 2) dif2 = i;
        }

        if (difNum > 2 || difNum == 1) return false;

        if (difNum == 0) return true;

        if (s1[dif1] == s2[dif2] && s1[dif2] == s2[dif1]) return true;

        return false;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();

        for (int i = 0; i < n; i++) U[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!cmp(strs[i], strs[j])) continue;
                //cout << strs[i] << "~" << strs[j] << endl;
                
                int ua = find(i), ub = find(j);
                U[ub] = ua;
            }
        }

        int res = 0;
        unordered_map<int, int> cou;
        for (int i = 0; i < n; i++){
            int ui = find(i);
            if (!cou[ui]) {
                res++, cou[ui]++;
            }
        }
        return res;
    }
}; 

// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
// stack

class Solution {
public:
    #define ppt properties
    
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = ppt.size();
        
        sort(ppt.begin(), ppt.end(), cmp);
        // for (auto& v : ppt) cout << v[0] << ":" << v[1] << endl;
        
        vector<int> st; int label = 0, res = 0;
        
        for (int i = 0; i < n; i++) {
            int x = ppt[i][0], y = ppt[i][1];
          
            if (!st.empty() && label < x) {
                while (!st.empty() && st.back() < y) {
                    st.pop_back(); res++;
                }
            }
   
            label = x; st.push_back(y);
        }
        
        return res;
    }
};

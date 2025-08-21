// https://leetcode.com/problems/rings-and-rods/
// hash map

class Solution {
public:
    int countPoints(string rings) {
        int n = rings.size();
        
        unordered_map<char, int> color;
        color['R'] = 1; color['G'] = 2; color['B'] = 3;
        
        unordered_map<int, int> rob;
        for (int i = 0; i < n; i += 2) {
            int c = color[rings[i]], r = rings[i + 1] - '0';
            rob[c * 10 + r]++;
        }
        
        int res = 0;
        for (int i = 0; i <= 9; i++)
            if (rob[10 + i] && rob[20 + i] && rob[30 + i])
                res++;
        return res;
    }
};

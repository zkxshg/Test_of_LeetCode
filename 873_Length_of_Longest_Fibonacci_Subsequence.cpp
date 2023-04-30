// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
// DP + hash table
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> dict;
        for (int i : arr) dict[i]++;
        
        unordered_map<int, unordered_map<int, int>> dpTable;
        
        int n = arr.size(), res = 0;
        
        //vector<int> dp(n, 2);
        
        for (int i = 2; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                int a2 = arr[i], a1 = arr[j];
                
                if (a2 - a1 >= a1) break;
                
                if (dict[a2 - a1]) {
                    int tm = 0;
                    if (!dpTable[a1][a2 - a1]) tm = 3;
                    else tm = dpTable[a1][a2 - a1] + 1;
                    dpTable[a2][a1] = tm;
                    res = max(res, tm);
                }
            }
        }
        
        // for (int i : dp) cout << i << endl;
        // for (int i : dp) res = max(res, i);
        
        if (res < 3) return 0;
        return res;
    }
};

// hash table
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        map<int, int> dict;
        for (int i : arr) dict[i]++;
        
        int n = arr.size(), res = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a1 = arr[i], a2 = arr[j], resi = 2;
                
                while (dict[a1 + a2]) {
                    resi++; res = max(res, resi);
                    int a3 = a1 + a2;
                    a1 = a2; a2 = a3;
                }
            }
        }
        
        return res;
    }
};

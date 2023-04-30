// https://leetcode.com/problems/slowest-key/
// hash table

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        
        vector<int> T(26); T[keysPressed[0] - 'a'] = releaseTimes[0];
        for (int i = 1; i < n; i++) {
            int num = keysPressed[i] - 'a';
            T[num] = max(T[num], releaseTimes[i] - releaseTimes[i - 1]);
        }
        
        int res = 0, maxT = 0;
        for (int i = 25; i >= 0; i--) {
            if (T[i] > maxT) {
                maxT = T[i]; res = i;
            }
        }
        
        return 'a' + res;
            
    }
};

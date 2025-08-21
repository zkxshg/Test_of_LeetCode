// https://leetcode.com/problems/count-largest-group/
// hash table

class Solution {
public:
    int acc(int n) {
        int res = 0;
        while (n) {
            res += n % 10; n /= 10;
        }
        return res;
    }
    
    int countLargestGroup(int n) {
        unordered_map<int, int> fre;
        
        int maxV = 0, maxF = 0;
        for (int i = 1; i <= n; i++) {
            int sd = acc(i);
            fre[sd]++;
            
            if (fre[sd] > maxV) {
                maxV = fre[sd]; maxF = 1;
            }
            else if (fre[sd] == maxV) maxF++;
        }
        return maxF;
    }
};

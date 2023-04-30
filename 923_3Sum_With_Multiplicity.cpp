// https://leetcode.com/problems/3sum-with-multiplicity/
// DP + successor Table

class Solution {
public:
    #define ll long long
    
    int threeSumMulti(vector<int>& arr, int target) {
        int len = arr.size();
        ll modV = 1e9 + 7;
        
        vector<vector<int> > sucT(101, vector<int>(len));

        for (int i = 0; i < 101; i++) {
            int count = 0;
            for (int j = len - 1; j >= 0; j--) {
                sucT[i][j] = count;
                if (arr[j] == i) count++;
            }
        }

        int res = 0;
        for (int i = 0; i < len - 2; i++) {
            for (int j = i + 1; j < len - 1; j++) {
                int aim = target - arr[i] - arr[j];
                if (aim > 100 || aim < 0) continue;
                res += sucT[aim][j];
                res %= modV;
            }
        }
        
        return res;  
    }
};

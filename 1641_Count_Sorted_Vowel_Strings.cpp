// math
class Solution {
public:
    int countVowelStrings(int n) {
        if (n == 1) return 5;
        
        vector<vector<int> > st(n, vector<int>(5, 1));
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 5; j++) st[i][j] = sumAll(st[i - 1], j);
        }
        
        return sumAll(st[n-1], 0);
    }
    
    int sumAll(vector<int> arr, int st) {
        int sum = 0;
        for (int i = st; i < 5; i++) sum += arr[i];
        return sum;
    }
};

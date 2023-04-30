// https://leetcode.com/problems/k-inverse-pairs-array/
// DP + math

class Solution {
public:
    #define ll long long
    
    int kInversePairs(int n, int k) {
        if (k == 0) return 1;
        
        int sum = 0; for (int i = 1; i < n; i++) sum += i;
        if (sum == k) return 1;
        else if (sum < k) return 0;
        
        int ub = 1e9 + 7;
        
        vector<ll> F(k + 2); F[0] = 1;
        
        int res = 0; int th = 0;
        for (int i = n - 1; i >= 1; i--) {
            vector<ll> tem(k + 2); tem[0] = 1;
            
            th = min(k, th + (n - i)); ll temSum = 0; int pos = 0, st = 0;
            for (int j = 1; j <= th; j++) {
                while (n - i + pos >= j && pos <= j) {
                    temSum = temSum + F[pos]; pos++;
                }
                while (n - i + st < j && st < pos) {
                    temSum = temSum - F[st]; st++; 
                }
                
                if (temSum < 0) temSum += ub;

                temSum %= ub;
                tem[j] = temSum;
            }
            F = tem;
        }

        return F[k] % ub;
    }
};

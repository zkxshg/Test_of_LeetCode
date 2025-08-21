// greedy
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int len = A.size(); 
        if (len == 1) return 0;
        
        sort(A.begin(), A.end());
        if (len == 2) return min(abs(A[0] + K - A[1] + K), A[1] - A[0]);
        
        int res = A[len - 1] - A[0];
        for (int i = 0; i < len - 1; i++) {
            res = min(res, max(A[i] + K, A[len - 1] - K) - min(A[0] + K, A[i + 1] - K));
            res = min(res, max(A[i + 1] + K, A[len - 1] - K) - min(A[0] + K, A[i] - K)); 
        }
            
        return res;
        
    }
};

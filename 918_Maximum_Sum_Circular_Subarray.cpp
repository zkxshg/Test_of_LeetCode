// DP
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int len = A.size();
        if(len == 1) return A[0];
        // old Kadane's algorithm
        int maxS = -60001;
        int curr = A[0], start = 0;
        for (int i = 1; i < len; i++) {
            curr = max(curr + A[i], A[i]);
            if (curr == A[i]) start = i;
            maxS = max(maxS, curr);
        }
        // Initial the accross part
        int rSum = 0;
        int rMax = -60001;
        for (int i = 0; i < start; i++) {
            rSum += A[i];
            rMax = max(rMax, rSum);
        }
        // Update accross Max
        for (int i = start; i < len; i++) {
            rMax = max(rMax, rSum);
            maxS = max(maxS, curr + rMax);
            rSum += A[i];
            curr -= A[i];
        }
        return maxS;
    }
};

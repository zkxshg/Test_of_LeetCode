// math
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        if (A.size() == 1) return 0;
        return max(0, *max_element(A.begin(),A.end()) - K - *min_element(A.begin(),A.end()) - K);
    }
};

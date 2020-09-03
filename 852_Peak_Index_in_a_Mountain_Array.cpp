// binary search
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int len = A.size();
        if (len == 3) return 1;
        
        int st = 0, en = len - 1;
        return biSearch(A, st, en);
    }
    
    int biSearch(vector<int>& A, int st, int en) {
        int mid = (st + en) / 2;
        if (mid == 0 || mid == A.size() - 1) return -1;
        
        if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) return mid;
        if (A[mid] < A[mid - 1]) return biSearch(A, st, mid);
        return biSearch(A, mid, en);
    }
};

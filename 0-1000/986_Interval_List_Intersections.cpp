// Two Points
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int lenA = A.size(), lenB = B.size(), Apos = 0, Bpos = 0;
        vector<vector<int>> result;
        while (Apos < lenA && Bpos < lenB) {
            if (B[Bpos][0] > A[Apos][1]) Apos++;
            else if (B[Bpos][1] < A[Apos][0]) Bpos++;
            else {
                int left = max(A[Apos][0], B[Bpos][0]);
                int right = min(A[Apos][1], B[Bpos][1]);
                vector<int> temp;
                temp.push_back(left);
                temp.push_back(right);
                result.push_back(temp);
                if (A[Apos][1] > B[Bpos][1]) Bpos++;
                else Apos++;
            }
        }
        return result;  
    }
};

// https://leetcode.com/problems/advantage-shuffle/
// Quick Sort + Greedy: O(n)
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int alen = A.size(), blen = B.size();
        sort(A.begin(), A.end());
        
        vector<int> Bi(blen); 
        for (int i = 0; i < blen; i++) Bi[i] = i;
        
        vector B2(B);
        QuickSortWithIndex(B2, Bi, 0, blen - 1);
        
        vector<int> res(alen); vector<int> rest;
        int apos = 0;
        
        for (int bi : Bi) {
            if (apos >= alen) {
                res[bi] = rest.back();
                rest.pop_back();
            }
            else {
                while (apos < alen && A[apos] <= B[bi]) {
                    rest.push_back(A[apos]); apos++;
                }
                
                if (apos < alen) {
                    res[bi] = A[apos]; apos++;
                }
                else {
                    res[bi] = rest.back(); rest.pop_back();
                }
            } 
        }
        
        return res;
    }
    
    void QuickSortWithIndex(vector<int>& B, vector<int>& BI, int f, int l) {
    int x = B[f];
    int i = f + 1;
    int j = l;
    while (i < j) {
        while (j >= f + 1 && B[j] >= x) j--;
        while (i <= l && B[i] <= x) i++;
        if (i < j) {
            int temp = B[i];
            B[i] = B[j];
            B[j] = temp;

            int tempI = BI[i];
            BI[i] = BI[j];
            BI[j] = tempI;
        }
    }
    if (B[f] > B[j]) {
        B[f] = B[j];
        B[j] = x;

        int tempI = BI[f];
        BI[f] = BI[j];
        BI[j] = tempI;
    }
    if (f < j - 1) QuickSortWithIndex(B, BI, f, j - 1);
    if (j + 1 < l) QuickSortWithIndex(B, BI, j + 1, l);
    }
};

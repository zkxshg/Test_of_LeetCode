// https://leetcode.com/problems/sort-an-array/
// divide and conquer

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // QuickSort(nums, 0, nums.size() - 1);
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
    
    void mergeSort(vector<int>& B, int f, int l) {
        if (f == l) return;
        
        int mid = (f + l) / 2;
        
        mergeSort(B, f, mid);
        mergeSort(B, mid + 1, l);
        
        vector<int> temp(l - f + 1);
        
        int lpos = f, rpos = mid + 1;
        for (int i = 0; i < l - f + 1; i++) {
            if (lpos <= mid && rpos <= l) {
                if (B[lpos] <= B[rpos]) {temp[i] = B[lpos]; lpos++;}
                else {temp[i] = B[rpos]; rpos++;}
            }
            else if (lpos <= mid) {temp[i] = B[lpos]; lpos++;}
            else {temp[i] = B[rpos]; rpos++;}
        }
        
        for (int i = 0; i < l - f + 1; i++) B[f + i] = temp[i];
    }
    
    void QuickSort(vector<int>& B, int f, int l){
        int x = B[f];
        int i = f + 1;
        int j = l;
        
        while (i < j){
            while (j >= f + 1 && B[j] >= x) j--;  
            while (i <= l && B[i] <= x) i++;
            if (i < j){
                int temp = B[i];
                B[i] = B[j];
                B[j] = temp;
            }
        }
        
        if (B[f] > B[j]){
            B[f] = B[j];
            B[j] = x;
        }
        
        if (f < j-1) QuickSort(B, f, j-1);
        if (j+1 < l) QuickSort(B, j+1, l);
    }
};

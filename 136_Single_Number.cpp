// https://leetcode.com/problems/single-number/
// Quick sort -> linear compare
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return nums[0];
        
        QuickSort(nums, 0, nums.size()-1);
        for (int i = 0; i < nums.size(); i += 2){
            if (i == nums.size() - 1) return nums[i];
            if (nums[i] != nums[i+1]) return nums[i];
        }
        return 0;
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
// Use XOR 
int singleNumber(int A[], int n) {
    int result = 0;
    for (int i = 0; i<n; i++)
    {
		result ^=A[i];
    }
	return result;
}

// Quick sort
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int len = nums.size();
        
        if (len < 2) {
            vector<int> temp;
            return temp;
        }
        if (len == 2) return nums;
        
        vector<int> result;
        
        QuickSort(nums, 0, nums.size()-1);
        
        for (int i = 0; i < nums.size(); i += 2){
            if (i == nums.size() - 1) result.push_back(nums[i]);
            if (nums[i] != nums[i+1]) {
                result.push_back(nums[i]);
                if (result.size() == 2) break;
                nums.erase(nums.begin() + i);
                i -= 2;
            }
        }
        return result;
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

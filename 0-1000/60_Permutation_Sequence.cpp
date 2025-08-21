// same to 31_Next_Permutation.cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) nums.push_back(i);
        for (int i = 1; i < k; i++) nextPermutation(nums);
        string result = "";
        for (int i = 0; i < n; i++) result += to_string(nums[i]);
        return result; 
    }
    
 // 31_Next_Permutation.cpp
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len > 1){
            bool comple = false;
            int pos = len - 2;
            
            while(!comple){
                if (pos < 0){
                    QuickSort(nums, 0, len - 1);
                    break;
                }
                
                for (int i = len - 1; i > pos; i--){
                    if (nums[pos] < nums[i]){
                        int temp = nums[pos];
                        nums[pos] = nums[i];
                        nums[i] = temp;
                        QuickSort(nums, pos+1, len-1);
                        comple = true;
                        break;
                    }
                }
                pos--;
            }  
        }
        
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

//  unordered_map<int, int> sumDict;
class NumArray {
public:
    unordered_map<int, int> sumDict;
    
    NumArray(vector<int>& nums) {
        int tempsum = 0;
        for (int i = 0; i < nums.size(); i++){
            tempsum += nums[i];
            sumDict[i] = tempsum;
        }
        sumDict[-1] = 0;
    }
    
    int sumRange(int i, int j) {
        return sumDict[j]-sumDict[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

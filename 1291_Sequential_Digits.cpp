// https://leetcode.com/problems/sequential-digits/
// backtracking
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for (int i = 1; i <= 9; i++) gener(i, result, low, high);
        sort(result.begin(), result.end());
        return result;
    }
    void gener(int val, vector<int>& result, int low, int high) {
        if (val <= high) {
            if (val >= low) result.push_back(val); 
            int last = val % 10;
            if (last < 9) {
                int temp = val * 10 + last + 1;
                gener(temp, result, low, high);
            }
        }
    }
};

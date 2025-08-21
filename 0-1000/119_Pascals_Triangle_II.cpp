// https://leetcode.com/problems/pascals-triangle-ii/
// same to 118. Pascal's Triangle
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result.push_back(1);
        if (rowIndex == 0) return result;
        if (rowIndex == 1) {
            result.push_back(1);
            return result;
        }
        vector<int> lowerR = getRow(rowIndex - 1);
        for (int i = 1; i < rowIndex; i++) result.push_back(lowerR[i-1] + lowerR[i]);
        result.push_back(1);
        return result;
    }
};

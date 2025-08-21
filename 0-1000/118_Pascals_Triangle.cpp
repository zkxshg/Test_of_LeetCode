// https://leetcode.com/problems/pascals-triangle/
// In Pascal's triangle, each number is the sum of the two numbers directly above it. 
// Pas[i] = result[num-2][i-1] + result[num-2][i];
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > result;
        if (numRows == 0) return result;
        vector<int> res1;
        res1.push_back(1);
        result.push_back(res1);
        if (numRows == 1) return result;
        for (int i = 2; i < numRows + 1; i++) result.push_back(generPas(i, result));
        return result;
    }
    vector<int> generPas(int num, vector<vector<int>> result){
        vector<int> Pas(num);
        Pas[0] = 1;
        Pas[num-1] = 1;
        for (int i = 1; i < num-1; i++) Pas[i] = result[num-2][i-1] + result[num-2][i];
        return Pas;
    }
};

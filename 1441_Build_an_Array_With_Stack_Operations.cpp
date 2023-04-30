// https://leetcode.com/problems/build-an-array-with-stack-operations/
// stack
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        reverse(target.begin(), target.end());
        for (int i = 1; i <= n; i++) {
            if (i == target.back()) {
                res.push_back("Push"); target.pop_back();
            }
            else {
                res.push_back("Push"); res.push_back("Pop");
            }
            
            if (target.empty()) break;
        }
        return res;
    }
};

// https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/description/
// bitmask

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int num = requests.size(), ub = (1 << num);
        
        int res = 0;
        for (int mask = 0; mask < ub; mask++) {
            bitset<32> bitmask(mask);
            vector<int> balance(n, 0);

            for (int i = 0; i < num; ++i) {
                if (bitmask[i]) {
                    --balance[requests[i][0]];
                    ++balance[requests[i][1]];
                }
            }

            bool achievable = true;
            for (int b : balance) {
                if (b != 0) {
                    achievable = false;
                    break;
                }
            }

            if (achievable) {
                res = max(res, (int)bitmask.count());
            }
        }

        return res;
    }
};

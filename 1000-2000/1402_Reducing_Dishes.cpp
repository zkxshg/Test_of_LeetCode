// https://leetcode.com/problems/reducing-dishes/description/
// Sorting

class Solution {
public:
    #define ll long long
    #define sat satisfaction

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = sat.size();
        sort(sat.begin(), sat.end());

        ll res = 0, acc = 0;
        while (!sat.empty()) {
            if (acc + sat.back() > 0) {
                acc += sat.back(); res += acc; 
                sat.pop_back();
            }
            else break;
        }

        return res;
    }
};

// 2561. Rearranging Fruits
// Link: https://leetcode.com/problems/rearranging-fruits/
// Lang: C++
// Date: 2025-08-21 20:52:46.442 UTC

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> fre;
        for (int x : basket1) fre[x]++;
        for (int x : basket2) fre[x]++;

        for (auto& [val, cnt] : fre) {
            if (cnt % 2 != 0) return -1;
        }

        unordered_map<int, int> fre1;
        for (int x : basket1) fre1[x]++;

        vector<int> q1, q2;
        for (auto& [val, cnt] : fre) {
            int need = cnt / 2;
            if (fre1[val] > need) {
                for (int i = 0; i < fre1[val] - need; ++i)
                    q1.push_back(val);
            }
            else if (fre1[val] < need) {
                for (int i = 0; i < need - fre1[val]; ++i)
                    q2.push_back(val);
            }
        }

        sort(q1.begin(), q1.end());
        sort(q2.begin(), q2.end(), greater<int>());

        int minAll = min(*min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end()));

        long long cost = 0;
        for (int i = 0; i < q1.size(); ++i) {
            cost += min({q1[i], q2[i], 2 * minAll});
        }

        return cost;
    }
};

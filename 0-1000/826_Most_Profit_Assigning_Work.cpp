// https://leetcode.com/problems/most-profit-assigning-work/?envType=daily-question&envId=2024-06-18
// Sorting + Stack + Greedy

class Solution {
public:
    #define pii pair<int, int>

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();

        // Step 1: Combine profit and difficulty into a vector of pairs and sort
        vector<pii> VP;
        for (int i = 0; i < n; ++i) VP.push_back({profit[i], difficulty[i]});

        sort(VP.begin(), VP.end(), [](const pii& a, const pii& b) {
            return (a.first < b.first) || (a.first == b.first && a.second > b.second);
        });

        // Step 2: Simplify VP using a stack
        vector<pii> ST;
        for (auto& v : VP) {
            while (!ST.empty() && v.first >= ST.back().first && v.second <= ST.back().second) {
                ST.pop_back();
            }
            ST.push_back(v);
        }

        // Step 3: Sort worker abilities
        sort(worker.begin(), worker.end());

        // Step 4: Use binary search to find maximum profit for each worker
        int maxProfit = 0;
        int j = 0; // Pointer for ST
        for (int ability : worker) {
            while (j < ST.size() && ST[j].second <= ability) j++;
            if (j > 0) maxProfit += ST[j - 1].first;
        }

        return maxProfit;
    }
};

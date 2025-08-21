// https://leetcode.com/problems/time-needed-to-buy-tickets/
// Queue

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0, n = tickets.size(), m = tickets[k];
        for (int i = 0; i <= k; i++) res += min(tickets[i], m);
        for (int i = k + 1; i < n; i++) res += min(tickets[i], m - 1);
        return res;
    }
};

// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/
// greedy + sort
 
class Solution {
public:
    #define pii pair<int, int>

    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();

        vector<int> order;
        for (int i = 0; i < n; i++) order.push_back(ceil(double(dist[i]) / speed[i]));
        sort(order.begin(), order.end());

        int cost = 1;
        for (int i : order) {
            int wp = (i > 0) ? i : 1;

            if (wp >= cost) cost++;
            else return wp;
        }
        
        return n;
    }
};

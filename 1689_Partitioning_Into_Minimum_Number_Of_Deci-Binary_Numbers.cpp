// greedy
class Solution {
public:
    int minPartitions(string n) {
        int maxN = 0;
        for (char ch : n) maxN = max(maxN, ch - '0');
        return maxN;
    }
};

// https://leetcode.com/problems/hand-of-straights/?envType=daily-question&envId=2024-06-06
// Greedy + hash table

class Solution {
public:
    #define gs groupSize

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % gs) return false;

        sort(hand.begin(), hand.end());

        unordered_map<int, int> fre;
        for (int i : hand) fre[i]++;

        for (int i = 0; i < n; i++) {
            int t = hand[i];
            if (fre[t] > 0) {
                fre[t]--;
                for (int j = 1; j < gs; j++) {
                    if (fre[t + j] <= 0) return false;
                    fre[t + j]--;
                }
            }
        }

        return true;
    }
};

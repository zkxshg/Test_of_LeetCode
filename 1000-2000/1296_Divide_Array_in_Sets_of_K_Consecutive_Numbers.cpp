// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
// Greedy + hash table

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        vector<int> hand = nums;
        int gs = k;
        
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

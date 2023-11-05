// https://leetcode.com/problems/find-the-winner-of-an-array-game/description/
// Array

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        unordered_map<int, int> fre;

        int n = arr.size(), top = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] > top) top = arr[i];
            fre[top]++;

            if (fre[top] >= k) break;
        }

        return top;
    }
};

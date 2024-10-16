// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/?envType=daily-question&envId=2024-10-01
// Hash table

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();

        unordered_map<int, int> fre;
        for (int i : arr) fre[i % k >= 0 ? i % k : i % k + k]++;

        if (fre[0] % 2) return false;

        for (int i = 1; i <= k / 2; i++) {
            if (fre[i] != fre[k - i]) return false;
        } 

        return true;
    }
};

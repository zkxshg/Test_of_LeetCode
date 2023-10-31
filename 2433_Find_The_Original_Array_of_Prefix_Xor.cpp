// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/?envType=daily-question&envId=2023-10-31
// Bit manipuation

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();

        for (int i = n - 1; i > 0; i--) {
            pref[i] = (pref[i - 1] ^ pref[i]);
        }

        return pref;
    }
};

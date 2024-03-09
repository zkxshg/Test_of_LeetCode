// https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-03-09
// hash map

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> fre;
        for (int i : nums1) fre[i]++;

        int res = INT_MAX;
        for (int i : nums2) {
            if (fre[i]) res = min(res, i);
        }

        if (res >= INT_MAX) return -1;
        return res;
    }
};

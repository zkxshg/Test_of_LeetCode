// https://leetcode.com/problems/height-checker/?envType=daily-question&envId=2024-06-10
// Sorting

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> nh = heights;
        sort(nh.begin(), nh.end());
        int res = 0;
        for (int i = 0; i < nh.size(); i++)
            if (nh[i] != heights[i])
                res++;
        return res;
    }
};

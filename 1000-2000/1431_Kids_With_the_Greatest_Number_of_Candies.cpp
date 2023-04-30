// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/
// array

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int ub = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        for (int kid : candies) {
            if (kid + extraCandies >= ub) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};

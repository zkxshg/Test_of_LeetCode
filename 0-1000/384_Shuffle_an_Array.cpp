// https://leetcode.com/problems/shuffle-an-array/
// Randomized / random_shuffle()

class Solution {
public:
    vector<int> res;
    
    Solution(vector<int>& nums) {
        res = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return res;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shu = res;
        random_shuffle(shu.begin(), shu.end());
        return shu;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/?envType=daily-question&envId=2024-06-24
// Sliding Window + Queue + Bit manipulation

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int min_flips = 0;
        bool flips = false; 
        deque<int> flip_indices;
        
        for (int i = 0; i < n; ++i) {
            if (!flip_indices.empty() && flip_indices.front() + k == i) {
                flip_indices.pop_front();
                flips = !flips;
            }
            
            if (nums[i] == flips) {
                if (i + k > n) return -1;
                
                flip_indices.push_back(i);
                flips = !flips; 
                min_flips++;
            }
        }
        
        return min_flips;
    }
};

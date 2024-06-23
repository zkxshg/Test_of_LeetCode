// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/?envType=daily-question&envId=2024-06-23
// Sliding Window + Monotonic Queue

class Solution {
public:
    void printDeque(const deque<int>& dq) {
        cout << "Deque contents: ";
        for (int num : dq) {
            cout << num << " ";
        }
        cout << endl;
    }

    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int left = 0, res = 0;

        for (int right = 0; right < nums.size(); ++right) {
            // Maintain the deque for maximum values
            while (!maxDeque.empty() && nums[maxDeque.back()] < nums[right])
                maxDeque.pop_back();
            maxDeque.push_back(right);
            
            // Maintain the deque for minimum values
            while (!minDeque.empty() && nums[minDeque.back()] > nums[right])
                minDeque.pop_back();
            minDeque.push_back(right);
            
            // Check if the current window is valid
            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                // Move the left end of the window to the right
                if (maxDeque.front() <= left)
                    maxDeque.pop_front();
                if (minDeque.front() <= left)
                    minDeque.pop_front();
                left++;
            }
            
            // Update the result with the size of the current valid window
            res = max(res, right - left + 1);

            printDeque(maxDeque);
            printDeque(minDeque);
        }
        
        return res;
    }
};

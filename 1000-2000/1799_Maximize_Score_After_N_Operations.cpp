// https://leetcode.com/problems/maximize-score-after-n-operations/description/
// Backtracking + Memorization

class Solution {
public:
    int Len;
    unordered_map<int, int> memo;

    int gcd(int x, int y) {
        if (y == 0) {
            return x;
        }
        return gcd(y, x % y);
    }

    // Bitmask to save the state of nums.
    int getState(vector<int>& nums) {
        int state = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != -1) {
                state |= (1 << i);
            }
        }
        return state;
    }

    int backtrack(vector<int>& nums, int current_operation) {
        if (current_operation > Len / 2) return 0;

        int state = getState(nums);
        // cout << bitset<16>(state) << endl;

        if (memo.find(state) != memo.end()) return memo[state];
            
        int max_score = 0, best_suc_score = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == -1) continue;
            
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == -1) continue;

                // Remove x and y from the array.
                int x = nums[i], y = nums[j];
                nums[i] = -1; nums[j] = -1;

                // Recursive call with memoization.
                best_suc_score = backtrack(nums, current_operation + 1);

                // Update the max result
                int new_score = best_suc_score + current_operation * gcd(x, y);
                max_score = max(max_score, new_score);

                // Add x and y back to the array.
                nums[i] = x; nums[j] = y;
            }
        }

        memo[state] = max_score;
        return max_score;
    }

    int maxScore(vector<int>& nums) {
        memo.clear();
        Len = nums.size();
        return backtrack(nums, 1);
    }
};

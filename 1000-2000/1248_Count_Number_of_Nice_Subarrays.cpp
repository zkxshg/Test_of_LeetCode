// https://leetcode.com/problems/count-number-of-nice-subarrays/description/?envType=daily-question&envId=2024-06-22
// Sliding window / hash table

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int st = 0, en = 0;
        int odd_num = 0;
        if (nums[0] & 1) odd_num++;

        int res = 0;
        while (en < n) {
            if (odd_num <= k) {
                if (odd_num == k) {
                    if (nums[st] & 1) res++;
                    else {
                        int i = 0;
                        while (st + i < en && !(nums[st + i] & 1)) i++; 
                        res += i + 1;
                    }
                }

                en++;
                if (en < n && (nums[en] & 1)) odd_num++;
            }
            else {
                if (nums[st] & 1) odd_num--;
                st++;
            }
        }

        return res;
    }
};

// 2 Hash table
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> countMap;
        countMap[0] = 1; // There's one way to have zero odd numbers before starting.

        int count = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            count += nums[i] & 1;  // Increment count if nums[i] is odd
            res += countMap[count - k];  // If (count - k) has occurred before, those are valid subarrays
            countMap[count]++;  // Record this count occurrence
        }

        return res;
    }
};

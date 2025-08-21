// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/
// Binary search + greedy

class Solution {
public:
    bool validPairs(vector<int>& sortedNums, int maxDiff, int p) {
        int pairCount = 0;
        
        for (int i = 0, j = 1; j < sortedNums.size();) {
            if (sortedNums[j] - sortedNums[i] <= maxDiff) {
                pairCount++;
                i = j + 1;
                j = i + 1;

                if (pairCount >= p) {
                    return true;
                }
            } else {
                i = j; j = i + 1;
            }
        }

        return false;
    }

    int minMaxDifference(vector<int>& sortedNums, int p) {
        sort(sortedNums.begin(), sortedNums.end());
        
        int left = 0;
        int right = sortedNums.back() - sortedNums.front();
        int ans = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (validPairs(sortedNums, mid, p)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }

    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        
        return minMaxDifference(nums, p);
    }
};

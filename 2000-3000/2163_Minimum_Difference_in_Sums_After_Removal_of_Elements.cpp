// 2163. Minimum Difference in Sums After Removal of Elements
// Link: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/
// Lang: C++
// Date: 2025-08-21 21:01:05.854 UTC

class Solution {
public:
    #define ll long long
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m / 3;

        // Minimum sum
        vector<ll> dp1(n + 1);
        priority_queue<ll> maxHeap;
        ll sumLeft = 0;

        for (int i = 0; i < n; ++i) {
            sumLeft += nums[i];
            maxHeap.push(nums[i]);
        }
        dp1[0] = sumLeft;


        for (int i = 1; i <= n; ++i) {
            int idx = (n - 1) + i; 
            sumLeft += nums[idx];
            maxHeap.push(nums[idx]);

            sumLeft -= maxHeap.top();
            maxHeap.pop();
            dp1[i] = sumLeft;
        }

        // Maximum sum 
        vector<ll> dp2(n + 1);
        priority_queue<ll, vector<ll>, greater<ll>> minHeap;
        ll sumRight = 0;

        for (int i = 2 * n; i < 3 * n; ++i) {
            sumRight += nums[i];
            minHeap.push(nums[i]);
        }
        dp2[0] = sumRight;

        for (int i = 1; i <= n; ++i) {
            int idx = 2 * n - i;  
            sumRight += nums[idx];
            minHeap.push(nums[idx]);

            sumRight -= minHeap.top();
            minHeap.pop();
            dp2[i] = sumRight;
        }

        ll answer = LLONG_MAX;
        for (int i = 0; i <= n; ++i) {
            answer = min(answer, dp1[i] - dp2[n - i]);
        }

        return answer;
    }

};

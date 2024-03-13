// https://leetcode.com/problems/find-the-pivot-integer/
// math

class Solution {
public:
    int pivotInteger(int n) {
        int sum = (1 + n) * n / 2;

        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) {
            arr[i] = arr[i - 1] + i;
            if (arr[i] * 2 == sum + i) return i;
        }

        return-1;
    }
};

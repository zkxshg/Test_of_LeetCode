// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
// array

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), nd4 = n / 4;
        for (int i = 1; i <= 4; i++) {
            int aim = 0;

            if (n < 4) aim = arr[0];
            else aim = arr[i * nd4 - 1];

            int st = upper_bound(arr.begin(), arr.end(), aim - 1) - arr.begin();
            int en = upper_bound(arr.begin(), arr.end(), aim) - arr.begin();

            if (en - st > nd4) return aim;
        }

        return -1;
    }
};

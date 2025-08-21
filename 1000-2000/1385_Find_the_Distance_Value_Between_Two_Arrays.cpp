// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
// binary search

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        
        int res = 0, n = arr2.size();
        for (int i : arr1) {
            int pos = lower_bound(arr2.begin(), arr2.end(), i) - arr2.begin();
            
            if (pos <= 0) {
                if (abs(arr2[pos] - i) > d) res++;
            }
            else if (pos >= n) {
                if (abs(arr2[pos - 1] - i) > d) res++;
            }
            else {
                if (abs(arr2[pos] - i) > d && abs(arr2[pos - 1] - i) > d) res++;
            }
        }
        
        return res;
    }
};

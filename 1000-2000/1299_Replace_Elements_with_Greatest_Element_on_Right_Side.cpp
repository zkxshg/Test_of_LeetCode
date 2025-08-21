// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side
// search max
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int m = arr.back(), len = arr.size();        
        arr[len - 1] = -1;
        for (int i = len - 2; i >= 0; i--) {
            int tem = arr[i];
            arr[i] = m;
            if (tem > m) m = tem;
        }
        return arr;
    }
};

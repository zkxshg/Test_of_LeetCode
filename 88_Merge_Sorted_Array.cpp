// straight insertion sort
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int temp = 0;
        int index = 0;
        for (int i = 0; i < n; i++){
            while (nums1[index] < nums2[i] && index < m + i) index++;
            for (int j = m+i; j > index; j--) nums1[j] = nums1[j-1]; 
            nums1[index] = nums2[i];
        }
    }
};

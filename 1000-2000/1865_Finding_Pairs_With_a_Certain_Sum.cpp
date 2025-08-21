// 1865. Finding Pairs With a Certain Sum
// Link: https://leetcode.com/problems/finding-pairs-with-a-certain-sum/
// Lang: C++
// Date: 2025-08-21 21:04:11.829 UTC

class FindSumPairs {
public:
    unordered_map<int, int> fre2;
    vector<int> arr1, arr2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1; arr2 = nums2;

        fre2.clear();
        for (int i : nums2) fre2[i]++;
    }
    
    void add(int index, int val) {
        fre2[arr2[index]]--;
        arr2[index] += val;
        fre2[arr2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for (int i : arr1) res += fre2[tot - i];
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

// https://leetcode.com/problems/find-the-difference-of-two-arrays/
// hash table

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> n1;
        unordered_map<int, int> n2;
        
        for (int i : nums1) n1[i]++;
        for (int i : nums2) n2[i]++;
        
        set<int> a1; set<int> a2;
        
        for (int i : nums1) if (!n2[i]) a1.insert(i);
        for (int i : nums2) if (!n1[i]) a2.insert(i);
        
        vector<int> v1; v1.assign(a1.begin(), a1.end());
        vector<int> v2; v2.assign(a2.begin(), a2.end());
        
        return {v1, v2};
    }
};

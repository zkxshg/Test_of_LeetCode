// hash map
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        
        unordered_map<int, int> pos;
        for (int i = 0; i < len2; i++) pos[nums2[i]] = i;
        
        vector<int> res;
        for (int i : nums1) {
            bool got = false;
            for (int j = pos[i] + 1; j < len2; j++) {
                if (nums2[j] > i) {
                    res.emplace_back(nums2[j]);
                    got = true; break;
                }
            }
            if (!got) res.emplace_back(-1);
        }
        
        return res;
    }
};

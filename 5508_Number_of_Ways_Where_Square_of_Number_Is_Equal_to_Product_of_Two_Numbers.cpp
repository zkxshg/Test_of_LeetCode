class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dic1;
        unordered_map<int, int> dic2;
        
        for (int n1 : nums1) dic1[n1]++;
        for (int n2 : nums2) dic2[n2]++;
        
        int result = 0;
        for (int n1 : nums1) {
            for (int n2 : nums2) {
                if (n1 * n1 % n2 == 0) {
                    long long int oth2 =  n1 * n1 / n2; 
                    if (oth2 > INT_MAX) continue;
                    if (oth2 == n2) {
                        if (dic2[oth2] > 1) result += dic2[oth2] - 1;
                    }
                    else if (dic2[oth2] > 0) result += dic2[oth2];
                }
            }
        }
        
        for (int n2 : nums2) {
            for (int n1 : nums1) {
                if (n2 * n2 % n1 == 0) {
                    long long int oth1 = n2 * n2 / n1; 
                    if (oth1 > INT_MAX) continue;
                    if (oth1 == n1) {
                        if (dic1[oth1] > 1) result += dic1[oth1] - 1;
                    }
                    else if (dic1[oth1] > 0) result += dic1[oth1];
                }
            }
        }
        
        return result / 2;
    }
};

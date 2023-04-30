// 5508_Number_of_Ways_Where_Square_of_Number_Is_Equal_to_Product_of_Two_Numbers.cpp
// hash table + int overflow
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dic1;
        unordered_map<int, int> dic2;
        
        for (int n1 : nums1) dic1[n1]++;
        for (int n2 : nums2) dic2[n2]++;
        
        double eps = 1e-10; 
        int result = 0;
        for (int n1 : nums1) {
            for (int n2 : nums2) {
                double t1 = (double)n1 / n2;
                double t2 = t1 * n1;
                if (t2 - (double)((int)t2) < eps) {
                    long oth2 = t2; 
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
                double t1 = (double)n2 / n1;
                double t2 = t1 * n2;
                if (t2 - (double)((int)t2) < eps) {
                    long oth1 = t2; 
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

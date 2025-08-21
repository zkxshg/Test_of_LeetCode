// https://leetcode.com/problems/median-of-two-sorted-arrays/
// Binary Search

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        
        int aim = (m + n) / 2 + 1;
        
        int st = 0, en = m - 1, mid = (st + en) / 2;
        while (st <= en) {
            mid = (st + en) / 2;
            
            if (mid > aim) {
                en = mid; continue;
            }
            // m position
            int midV = nums1[mid];
            // n position
            int nPosUB = upper_bound(nums2.begin(), nums2.end(), midV) - nums2.begin();
            int nPosLB = lower_bound(nums2.begin(), nums2.end(), midV) - nums2.begin();
            // total position
            int posUB = mid + 1 + nPosUB;
            int posLB = mid + 1 + nPosLB;
            //cout << "pos = " << pos << ", mid = " << mid << endl;
            // if mid is median
            if (posLB <= aim && aim <= posUB) {
                int nPos = aim - mid - 1;
                if ((m + n) % 2) return nums1[mid];
                else {
                    // even case
                    int mPre = (mid > 0) ? nums1[mid - 1] : INT_MIN;
                    int nPre = (nPos > 0) ? nums2[nPos - 1] : INT_MIN;
                    
                    if (mPre < nPre) return double(nums1[mid] + nums2[nPos - 1]) / 2;
                    else return double(nums1[mid] + nums1[mid - 1]) / 2;
                }
            }
            else if (posUB < aim) st = mid + 1;
            else {
                if (st == en) break;
                en = mid;
            }
        }
        
        st = 0, en = n - 1, mid = (st + en) / 2;
        while (st <= en) {
            mid = (st + en) / 2;
            
            if (mid > aim) {
                en = mid; continue;
            }
            // m position
            int midV = nums2[mid];
            // n position
            int mPosUB = upper_bound(nums1.begin(), nums1.end(), midV) - nums1.begin();
            int mPosLB = lower_bound(nums1.begin(), nums1.end(), midV) - nums1.begin();
            // total position
            int posUB = mid + 1 + mPosUB;
            int posLB = mid + 1 + mPosLB;
            // if mid is median
            if (posLB <= aim && aim <= posUB) {
                if ((m + n) % 2) return nums2[mid];
                else {
                    int mPos = aim - mid - 1;
                    // even case
                    int mPre = (mid > 0) ? nums2[mid - 1] : 0;
                    int nPre = (mPos > 0) ? nums1[mPos - 1] : 0;
                    // cout << mPre << ":" << nPre << endl;
                    if (mPre < nPre) return double(nums2[mid] + nums1[mPos - 1]) / 2;
                    else return double(nums2[mid] + nums2[mid - 1]) / 2;
                }
            }
            else if (posUB < aim) st = mid + 1;
            else {
                if (st == en) break;
                en = mid;
            }
        }
        
        return -1;
    }
};

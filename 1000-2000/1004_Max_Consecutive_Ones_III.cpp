// https://leetcode.com/problems/max-consecutive-ones-iii/
// Sliding Window + RLE

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return (nums[0] + k > 0);
        
        vector<int> rle;
        if (nums[0]) rle.push_back(1);
        else rle.push_back(0);
        
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            
            if (nums[i] && rle.back()) rle.back()++;
            else if (nums[i]) rle.push_back(1);
            else rle.push_back(0);
        }
        //for (int i : rle) cout << i << ","; cout << endl;
        int res = 0, rlen = rle.size();
        
        int st = 0, en = 0, tk = k, tem = 0; 
        while (tk > 0 && en < rlen) {
            if (rle[en]) tem += rle[en];
            else if (tk > 0) {
                tk--; tem++;
            }
            else break;
            
            en++;
        }
        res = tem; 
        
        while (en < rlen && st < rlen) {
            
            if (rle[st]) tem -= rle[st];
            else {
                tem--; tk++;
            }
            st++;
            
            while (tk >= 0 && en < rlen) {
                if (rle[en] > 0) tem += rle[en];
                else if (tk > 0) {
                    tk--; tem++;
                }
                else break;
                
                en++;
            }
            
            res = max(res, tem);
        }
        
        return res;
    }
};

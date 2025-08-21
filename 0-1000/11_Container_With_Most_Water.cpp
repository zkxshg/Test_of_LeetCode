// https://leetcode.com/problems/container-with-most-water/
// Greedy + Two pointers
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int st = 0, en = n - 1;
        int res = vol(st, en, height);
        
        while (st < en) {
            if (height[st] < height[en]) {
                while (st < en - 1 && height[st + 1] <= height[st]) st++;
                st++;
                res = max(res, vol(st, en, height));
            }
            else {
                while (en > st + 1 && height[en - 1] <= height[en]) en--;
                en--;
                res = max(res, vol(st, en, height));
            }
        }
        
        return res;
    }
    
    int vol(int s, int e, vector<int>& height) {
        return (e - s) * min(height[s], height[e]);
    }
};

// https://leetcode.com/problems/minimum-area-rectangle/
// set intersection + sorting

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),
                         insert_iterator<vector<int>>(res,res.begin()));
        return res;        
}
    int minAreaRect(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        if (points.size() < 4) return 0;
        
        vector<vector<int> > rowEle(40001);
        
        for (auto& p : points) rowEle[p[0]].push_back(p[1]);
        
        int res = INT_MAX;
        for (int i = 0; i < 40001; i++) {
            if (rowEle[i].size() < 2) continue;
            
            for (int j = i + 1; j < 40001; j++) {
                if (rowEle[j].size() < 2) continue;
                
                vector<int> y = intersect(rowEle[i], rowEle[j]);
                
                if (y.size() < 2) continue;
                
                for (int k = 0; k < y.size() - 1; k++) 
                    res = min(res, (j - i) * (y[k + 1] - y[k]));
                
            }
        }
        
        if (res >= INT_MAX) return 0;
        return res;
    }
};

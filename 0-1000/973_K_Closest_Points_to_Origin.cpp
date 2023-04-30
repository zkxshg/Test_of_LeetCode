// sort
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int len = points.size();
        
        vector<pair<int, int> > distA;
        
        for (int i = 0; i < len; i++) distA.push_back(make_pair(eucDis(points[i]), i));
        
        sort(distA.begin(), distA.end());
        
        vector<vector<int>> res;
        for (int i = 0; i < K; i++) res.push_back(points[distA[i].second]);
        return res;
    }
    
    int eucDis(vector<int>& a) {
        return pow(a[0], 2) + pow(a[1], 2);
    }
};

// sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int> > distA;
        
        unordered_map<int , int> couDict;
        
        for (int i : nums) couDict[i]++;
        
        for (auto& v : couDict) distA.push_back(make_pair(v.second, v.first));
        
        sort(distA.begin(), distA.end());
        
        int len = distA.size();
        vector<int> res;
        for (int i = 1; i <= k; i++) res.push_back(distA[len - i].second);
        return res;
    }
};

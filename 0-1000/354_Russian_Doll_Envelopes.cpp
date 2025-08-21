// DP + binary search
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        else return a[1] > b[1];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int len = envelopes.size(); if (len < 2) return len;
        
        sort(envelopes.begin(), envelopes.end(), cmp);
        
        //for (vector<int> v : envelopes)  cout << "[" << v[0] << "," << v[1] << "]" << ",";
        //cout << endl;
        
        int res = 0;
        
        vector<vector<vector<int>> > layer;
        layer.push_back({envelopes[0]});
        
        for (int i = 1; i < len; i++) {
            int l = layer.size();
            bool get = false;
            for (int j = l - 1; j >= 0; j--) {
                if (bisearch(envelopes[i], layer[j], 0, layer[j].size() - 1)) {
                    if (j < l - 1) layer[j + 1].push_back(envelopes[i]);
                    else layer.push_back({envelopes[i]});
                    get = true;
                    break;
                }
            }
            if (!get) layer[0].push_back(envelopes[i]);
        }
    
        return layer.size();
    }
    
    bool bisearch(vector<int>& a, vector<vector<int>>& lay, int st, int en) {
        if (st == en) {
            if (a[0] > lay[st][0] && a[1] > lay[st][1]) return true;
            return false;
        }
        
        int m = (st + en) / 2;
        
        if (a[0] > lay[m][0] && a[1] > lay[m][1]) return true;
        
        if (a[0] <= lay[m][0]) return bisearch(a, lay, st, m);
        return bisearch(a, lay, m + 1, en);
    }
    
};

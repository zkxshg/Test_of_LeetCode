// divide and conquer
class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res = {1};
        if (N == 1) return res;
        
        while (res.size() < N) {
            vector<int> temp;
            
            for (int i : res) {
                if (i * 2 - 1 <= N) temp.push_back(i * 2 - 1);
            }
            
            for (int i : res) {
                if (i * 2 <= N) temp.push_back(i * 2);
            }
            
            res = temp;
        }
        
        return res;
    }
    
};

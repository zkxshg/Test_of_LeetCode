// stack
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        reverse(arr.begin(), arr.end());
        
        bool got = true;
        
        while (got && arr.size() > 0) {
            got = false;
            
            for (vector<int> pi : pieces) {
                if (pi[0] == arr.back()) {
                    got = true;
                    for (int i : pi) {
                        if (i == arr.back()) arr.pop_back();
                        else return false;
                    }
                    break;
                }
            }

        }
        
        if (arr.size() == 0) return true;
        return false;
    }
};

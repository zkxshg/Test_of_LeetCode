// recurrence
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if (k < 1 || k > n) return result;
        else if (k == 1){
            for (int i = 1; i <= n; i++) result.push_back(vector<int>(1,i));
            return result;
        }
        else if (k == n){
            vector<int> listN;
            for (int i = 1; i <= n; i++) listN.push_back(i);
            result.push_back(listN);
            return result;
        }
        for (int i = n; i >= k; i--){
            vector<vector<int>> tempRes = combine(i-1, k-1);
            for (int j = 0; j < tempRes.size(); j++){
                vector<int> temp = tempRes[j];
                temp.push_back(i);
                result.push_back(temp);
            }
        }
        return result;
    }
};

// linear scan
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;
        
        int len = S.size();
        if (len < 3) return result;
        
        int pos = 0;
        while (pos < len - 1){
            if (S[pos] != S[pos + 1]) pos++;
            else{
                int left = pos;
                int cou = 1;
                while (pos < len - 1 && S[pos] == S[pos + 1]){
                    pos++;
                    cou++;
                }
                if (cou >= 3){
                    vector<int> temp;
                    temp.push_back(left);
                    temp.push_back(pos);
                    result.push_back(temp);
                }
                pos++;
            }
        }
        return result;
    }
};

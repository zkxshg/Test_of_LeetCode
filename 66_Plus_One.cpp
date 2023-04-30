//  内部进位
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int lend = digits.size();
        vector<int> result = {0};
        result.insert(result.end(),digits.begin(),digits.end());
        int len = lend + 1;
        result[len - 1] = result[len - 1] + 1;
        for (int i = 1; i < lend + 1; i++){
            if (result[len - i] <= 9) break;
            else {
                result[len - i] = 0;
                result[len - i - 1] = result[len - i - 1] + 1; 
            }
        }
        if (result[0] == 0) {
            vector<int> tr(result.begin()+1, result.end());
            result = tr;
        }
        return result;  
    }
};

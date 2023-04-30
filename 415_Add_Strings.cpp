// case1 : [0, len2] -> case2: [len2+1, len1]
class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        
        if (len1 == 0 && len2 == 0) return "";
        else if (len1 == 0) return num2;
        else if (len2 == 0) return num1;
        
        if (len1 < len2){
            string temp = num1;
            num1 = num2;
            num2 = temp;
            len1 = num1.size();
            len2 = num2.size();
        }
        int len = len1 + 1;
        string result(len, '0');
    
        for (int i = 1; i < len2 + 1; i++){
            int temp = (num1[len1 - i] - '0') + (num2[len2 - i] - '0') + (result[len - i] - '0');
            string tem = to_string(temp);
            if (temp > 9) {   
                result[len - i] = tem[1];
                result[len - i - 1] = tem[0];
            }
            else result[len - i] = tem[0];
        }
        for (int i = len2 + 1; i < len1 + 1; i++){
            int temp = (num1[len1 - i] - '0') + (result[len - i] - '0');
            string tem = to_string(temp);
            if (temp > 9) {
                result[len - i] = tem[1];
                result[len - i - 1] = '1';
            }
            else result[len - i] = tem[0];
        }
        if (result[0] == '0') result = result.substr(1, result.size()-1);
        return result;
    }
};

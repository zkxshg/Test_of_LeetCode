// https://leetcode.com/problems/multiply-strings/
// calcute each pos -> step-by-step carry
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
     
        if (len1 == 0 || len2 == 0) return "0";
        else if (num1 == "0" || num2 == "0") return "0";
        else if (num1 == "1") return num2;
        else if (num2 == "1") return num1;
        
        int len = len1 + len2 - 1;  
        vector<int> result(len, 0);
        
        for (int i = 0; i < len2; i++){
            for (int j = 0; j < len1; j++) result[i+j] += (num2[i]-'0') * (num1[j]-'0');
        }
      
        vector<int> rplus = {0};
        rplus.insert(rplus.end(),result.begin(),result.end());
        
        len += 1;
        for (int i = 1; i < len;i++){
            int temint = rplus[len - i];
            if (temint > 9) {
                rplus[len - i - 1] += temint / 10;
                rplus[len - i] = temint % 10;
            }
        }
        
        if (rplus[0] == 0) {
            vector<int> temr(rplus.begin()+1, rplus.end());
            rplus = temr;
            len -= 1;
        }
        string res = "";
        for (int i = 0; i < len; i++) res += to_string(rplus[i]);
        return res;
    }
};

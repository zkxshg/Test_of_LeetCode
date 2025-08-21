// https://leetcode.com/problems/integer-to-roman
// else if (num == 9){ temp += dic[mi]; temp += dic[mi+2]; return temp;}

class Solution {
public:
    string intToRoman(int num) {
        string numstr = to_string(num);
        int len = numstr.size();
        reverse(numstr.begin(), numstr.end());
        string dict = "IVXLCDM";
        string result = "";
        int index = 0;
        while (index < len)
        {
            int str_i = int(numstr[index]) - int('0');
            if (str_i != 0)
                result = itor(str_i, index, dict) + result;
            index++;
        }
        return result;
    }
    string itor(int num, int mi, string dic){
        mi = mi * 2;
        string temp = "";
        
        if (num <= 3)
        {
            for (int i = 0; i < num; i++) temp += dic[mi];
            return temp;
        }
        else if (num == 4)
        {
            temp += dic[mi];
            temp += dic[mi+1];
            return temp;
        }
        else if (num == 5)
        {
            temp += dic[mi+1];
            return temp;
        }
        else if (num <= 8)
        {
            temp += dic[mi+1];
            for (int i = 0; i < num - 5; i++) temp += dic[mi];
            return temp;
        }
        else if (num == 9)
        {
            temp += dic[mi];
            temp += dic[mi+2];
            return temp;
        }
        return "";
    }
};

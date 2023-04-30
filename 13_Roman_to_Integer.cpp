// https://leetcode.com/problems/roman-to-integer/
// if(p1 >= p2) { result += p1; pos += 1;}
// else { result += p2 - p1; pos += 2;}
class Solution {
public:
    int romanToInt(string s) {
        int len = s.size();
        int pos = 0;
        int result = 0;
        int p1 = 0;
        int p2 = 0;
        while (pos < len)
        {
            if (pos == len -1) 
            {
                result += trans(s[pos]);
                return result;
            }
            p1 = trans(s[pos]);
            p2 = trans(s[pos + 1]);
            if(p1 >= p2)
            {
                result += p1;
                pos += 1;
            }
            else
            {
                result += p2 - p1;
                pos += 2;
            }
        }
        return result;
    }
    int trans(char ch){
        if (ch == 'I')  return 1;
        else if (ch == 'V')  return 5;
        else if (ch == 'X')  return 10;
        else if (ch == 'L')  return 50;
        else if (ch == 'C')  return 100;
        else if (ch == 'D')  return 500;
        else if (ch == 'M')  return 1000;
        return 0;
    }
};

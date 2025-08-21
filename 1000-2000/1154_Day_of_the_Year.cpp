// https://leetcode.com/problems/day-of-the-year/
// Math

class Solution {
public:
    int dayOfYear(string date) {
        int year = 0;
        for (int i = 0; i < 4; i++) year = year * 10 + (date[i] - '0');
        
        bool leap = false;
        if (!(year % 4) && (year % 100 || !(year % 400))) leap = true;
        
        int month = 0;
        for (int i = 5; i < 7; i++) month = month * 10 + (date[i] - '0');
        
        int day = 0;
        for (int i = 8; i <= 9; i++) day = day * 10 + (date[i] - '0');
        
        unordered_map<int, int> monLen;
        vector<int> Day_31 = {1, 3, 5, 7, 8, 10, 12};
        vector<int> Day_30 = {4, 6, 9, 11};
        
        for (int i : Day_31) monLen[i] = 31;
        for (int i : Day_30) monLen[i] = 30;
        
        if (leap) monLen[2] = 29;
        else monLen[2] = 28;
        
        int res = 0;
        for (int i = 1; i < month; i++) res += monLen[i];
        res += day;
        
        return res;
    }
};

// https://leetcode.com/problems/angle-between-hands-of-a-clock/
// math
class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour == 12) hour = 0;
        double result = abs((30 - 30 * minutes / 60.0) + (minutes - (hour + 1) * 5) * 6);
        if (result > 180) return 360.0 - result;
        return result;
    }
};

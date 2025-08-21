// random
class Solution {
public:
    double R, x, y;
    double pi = M_PI;
    
    Solution(double radius, double x_center, double y_center) {
        R = radius; x = x_center; y = y_center;
    }
    
    vector<double> randPoint() {
        double len = sqrt((double)rand() / RAND_MAX) * R;
        double ang = (double)rand() / RAND_MAX * 2 * pi;
        double randx = x + len * cos(ang); 
        double randy = y + len * sin(ang); 

        return {randx, randy};
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
